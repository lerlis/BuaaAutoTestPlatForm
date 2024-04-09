#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (C) rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.

import time
import numpy as np

from utils import minAngleDiff,saturation,constrain_rad,get_foot,getLinearEquation,judge_side,GetCrossAngle


class sense_direction:
    def __init__(self):
        self.current_yaw_rad = 0

        self.kp_z = 3
        self.ki_z =  0
        self.kd_z = 0.8
        self.z_sat_I =  0.2

        self.kp_y = 0.8

        self.kp_yaw = 0.75
        self.ki_yaw =  0.1
        self.kd_yaw =  0
        self.yaw_sat_I =  0.2
        self.max_yaw_rate = np.deg2rad(30)
        
        self.max_v_cmd = 3


        
        # Reset
        self.reset()
    
    def reset(self):   
        self.last_yaw_err = 0.0
        self.yaw_err_i = 0.0
        


        self.in_time = 0.0

    

    def update_kinematics(self,yaw_rad,R_be):
        self.current_yaw_rad = yaw_rad
        # Rotation Matrix body2earth
        self.R_be = R_be

    def set_tgt_wp(self,wp,last_wp, offset_yaw, R_ei, mode=1):
        # tgt&last_pose in init FLU
        self.tgt_pose = wp["pose"]
        self.last_pose = np.array(last_wp["pose"])
        # calculate the fly direction of UAV
        line1 = [0,0,1,0] # init body direction x
        param = getLinearEquation(line1) # Ax+By+C=0,get A,B,C
        point = np.array([self.tgt_pose[0]-self.last_pose[0], self.tgt_pose[1]-self.last_pose[1]])
        side_sign = judge_side(param, point)
        side_sign = -side_sign # left is positive, right is negative
        line2 = [0, 0, point[0], point[1]]
        angle = GetCrossAngle(line1, line2)
        angle = side_sign * angle
        # fly direction
        if mode == 1: # 机头方向和航路保持一致，屏蔽了控制指令中的yaw，只保留位置控制指令
            self.tgt_yaw = angle # the head direction of UAV
        elif mode == 2: # 机头方向按照设定的控制指令给定（设定的yaw角）
            self.tgt_yaw = np.deg2rad(wp["tgt_yaw"])
        self.tgt_yaw_ENU = constrain_rad(angle + offset_yaw)
        # print("offset_yaw", offset_yaw)
        # print("tgt_yaw_init_flu:", angle, "tgt_yaw_ENU:", self.tgt_yaw_ENU)
        self.tgt_pose_ENU = R_ei.T.dot(self.tgt_pose)
        self.last_pose_ENU = R_ei.T.dot(self.last_pose)
        # Rotation Matrix  earth2ring
        self.R_er = np.array([
            [np.cos(self.tgt_yaw_ENU), -np.sin(self.tgt_yaw_ENU), 0],
            [np.sin(self.tgt_yaw_ENU),  np.cos(self.tgt_yaw_ENU), 0],
            [0, 0, 1]
        ])
        self.R_er = self.R_er.T 
        self.v_forward = wp["vel"]

        real_pos_flu = self.tgt_pose_ENU-self.last_pose_ENU
        self.re_pos_ring = self.R_er.dot(real_pos_flu)


    def sense_direction_update(self, current_enu_pos):
        time_scale = 0.8
        X,Y,Z = self.re_pos_ring

        base_pose_enu = current_enu_pos - self.last_pose_ENU
        # print('base_pose_enu', base_pose_enu)
        current_ring_pose = self.R_er.dot(base_pose_enu)
        x_c, y_c, z_c = current_ring_pose
        point = np.array([x_c, y_c])
        line = np.array([0, 0, X, Y])
        # Calculate the distance between current position and line
        curr_foot = get_foot(point, line)
        distance_y = np.linalg.norm(curr_foot - point)
        # print("distance_y:", distance_y,'next_tgt_ring', self.re_pos_ring, "current_pose", current_ring_pose)

        # Calculate the point is in which side of the line
        # line_param = getLinearEquation(line)
        # side_sign = judge_side(line_param, point) # left is negative, right is positive
        vy_err = self.kp_y * distance_y * (-np.sign(y_c)) # a little problem now, need to check
  
        pre_time = X/self.v_forward*time_scale
        vy_cmd = Y/pre_time + vy_err
        vz_cmd = Z/pre_time
        
        # ring frame v cmd
        v_cmd_ring = np.array([self.v_forward, vy_cmd, vz_cmd])
        v_cmd_earth = self.R_er.T.dot(v_cmd_ring)
        # print('v_cmd_earth', v_cmd_earth)
        v_cmd = self.R_be.T.dot(v_cmd_earth)
        # print('v_cmd', v_cmd)
        v_cmd = saturation(v_cmd,self.max_v_cmd)

        # test vy_err in body coordination
        # v_err = np.array([0,vy_err,0])
        # v_err_earth = self.R_er.T.dot(v_err)
        # v_err_body = self.R_be.T.dot(v_err_earth)
        # print('vy_err_body', v_err_body, 'vy_err:', vy_err, 'y_c: ', y_c)
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


if __name__=="__main__":
    from utils import eulerAngleToMatrix


    sd_ctrl = sense_direction()
    last_wp = {
        "pose": np.zeros(3),
        "tgt_yaw": 0,
    }
    cnt_wp = { 
        "pose": [3.80, 2, 1.5],
        "tgt_yaw": 0,
        "vel": 1.0,
        
    }

    sd_ctrl.set_tgt_wp(cnt_wp,last_wp)
    R_be = eulerAngleToMatrix([0,0,0])
    yaw = np.deg2rad(1.23)
    sd_ctrl.update_kinematics(yaw,R_be)
    v_cmd, yaw_rate_cmd = sd_ctrl.sense_direction_update()

    print(v_cmd)
    print(yaw_rate_cmd)