#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (C) rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.

import time
import numpy as np


from utils import minAngleDiff,saturation,constrain_rad,GetCrossAngle,getLinearEquation,judge_side


class sense_circle:
    def __init__(self):
        self.current_yaw_rad = 0

        self.kp_z = 3
        self.ki_z =  0
        self.kd_z = 0.8
        self.z_sat_I =  0.2

        self.kp_y = 0.5

        self.kp_yaw = 0.75
        self.ki_yaw =  0.1
        self.kd_yaw =  0
        self.yaw_sat_I =  0.2
        self.max_yaw_rate = np.deg2rad(30)
        
        self.max_v_cmd = 4

         # Reset
        self.reset()
    
    def reset(self):   
        self.last_yaw_err = 0.0
        self.yaw_err_i = 0.0

        self.in_time = 0.0

    def update_kinematics(self,yaw_rad,R_be, R_ei):
        self.current_yaw_rad = yaw_rad
        # Rotation Matrix body2earth
        self.R_be = R_be
        self.R_ei = R_ei

    def get_circle_info(self, circle_pos, init_yaw):
        self.circle_pos_init_flu = circle_pos
        self.start_time = time.time()
        self.start_init_yaw = init_yaw

    def update(self, current_enu_pos, ctrl_param, offset_yaw, mode=0):
        # 计算init_flu坐标系下无人机当前的位置
        self.current_pos_init_flu = self.R_ei.dot(current_enu_pos)
        if mode == 1:  # 时间基础的tgt_yaw设定
            self.tgt_yaw_temp = self.start_init_yaw + (time.time() - self.start_time) * ctrl_param[3]
            self.tgt_yaw = constrain_rad(self.tgt_yaw_temp)
            if self.tgt_yaw != self.tgt_yaw_temp:
                self.start_time = time.time()
                self.start_init_yaw = self.tgt_yaw
        else:
            # 计算相对于圆心的直线和init_flu的x轴夹角
            line1 = [0,0,1,0] # init body direction x
            param = getLinearEquation(line1) # Ax+By+C=0,get A,B,C
            point = np.array([self.current_pos_init_flu[0] - self.circle_pos_init_flu[0], self.current_pos_init_flu[1] - self.circle_pos_init_flu[1]])
            line2 = [0,0,point[0], point[1]]
            angle = GetCrossAngle(line1, line2)
            side_sign = judge_side(param, point)
            side_sign = -side_sign # left is positive, right is negative
            angle = side_sign * angle
            # 修正当前位置夹角为机头目标的yaw角
            if ctrl_param[2] == 0: # clockwise
                angle = np.rad2deg(angle) - 90
            elif ctrl_param[2] == 1:  # anti-clockwise
                angle = np.rad2deg(angle) + 90
            self.tgt_yaw = constrain_rad(np.deg2rad(angle))
            # print(np.rad2deg(self.tgt_yaw))
        self.tgt_yaw_ENU = constrain_rad(self.tgt_yaw + offset_yaw)
        # Rotation Matrix  earth2ring
        self.R_er = np.array([
            [np.cos(self.tgt_yaw_ENU), -np.sin(self.tgt_yaw_ENU), 0],
            [np.sin(self.tgt_yaw_ENU),  np.cos(self.tgt_yaw_ENU), 0],
            [0, 0, 1]
        ])
        self.R_er = self.R_er.T

        # v_cmd calculate
        v_forward = ctrl_param[1]
        check_dis = np.linalg.norm(self.circle_pos_init_flu[0:2]- self.current_pos_init_flu[0:2]) - ctrl_param[0]
        # print('distance_error:', check_dis)
        if ctrl_param[2] == 0: # clockwise
            vy_err = -1 * self.kp_y * check_dis  # a little problem now, need to check
        elif ctrl_param[2] == 1:  # anti-clockwise
            vy_err = self.kp_y * check_dis
        vz = 0

        v_cmd_tgt = np.array([v_forward, vy_err, vz])
        v_cmd_earth = self.R_er.T.dot(v_cmd_tgt)
        v_cmd = self.R_be.T.dot(v_cmd_earth)
        v_cmd = saturation(v_cmd, self.max_v_cmd)

        # Yaw control
        # ————————————————————————————————————————————
        yaw_err = minAngleDiff(self.tgt_yaw, self.current_yaw_rad)
        yaw_rate_cmd = self.kp_yaw*yaw_err + self.ki_yaw*self.yaw_err_i
        yaw_rate_cmd = saturation(yaw_rate_cmd,self.max_yaw_rate)

        self.last_yaw_err = yaw_err
        self.yaw_err_i = self.yaw_err_i + self.last_yaw_err
        self.yaw_err_i = np.sign(self.yaw_err_i) * min(abs(self.yaw_err_i), self.yaw_sat_I)
        # ————————————————————————————————————————————

        return v_cmd, yaw_rate_cmd


if __name__ == "__main__":
    sc_ctrl = sense_circle()
    sc_ctrl.get_circle_info([25,-10,10])
    sc_ctrl.update([15,-10,1520])  # 简单起见，直接输入的init_flu坐标系下的坐标，仅供测试使用
