#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (C) RflySim from Central South University and
# rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import numpy as np
import re
import os
from openpyxl import Workbook
import datetime

# 饱和
def saturation(a, maxv):
    n = np.linalg.norm(a) if type(a) is np.ndarray else a
    if abs(n) > maxv:
        return a / abs(n) * maxv
    else:
        return a


# 角度差计算
def minAngleDiff(a, b):
    diff = a - b
    if diff < 0:
        diff += 2*np.pi
    if diff < np.pi:
        return diff
    else:
        return diff - 2*np.pi

# 限制角度在-pi~pi
def constrain_rad(ori_rad):
    delta_rad = 0
    if ori_rad > np.pi:
        delta_rad = -2*np.pi
    if ori_rad < -np.pi:
        delta_rad = 2*np.pi
    return ori_rad + delta_rad



def eulerAngleToMatrix(rpy):
    # 实际上全都用FLU系的
    # Z-Y-X
    R_x = np.array([
            [1,                  0,                   0],
            [0, np.cos(rpy[0]), -np.sin(rpy[0])],
            [0,  np.sin(rpy[0]), np.cos(rpy[0]) ]
        ] ,dtype=float
    )
                        
    R_y = np.array([
            [np.cos(rpy[1]), 0, np.sin(rpy[1])],
            [0,                  1,                  0],
            [-np.sin(rpy[1]), 0, np.cos(rpy[1])]
        ],dtype=float
    )
                
    R_z = np.array([
            [np.cos(rpy[2]), -np.sin(rpy[2]), 0],
            [np.sin(rpy[2]), np.cos(rpy[2]),  0],
            [0,                  0,                   1]
        ],dtype=float
    )
                    
    R = np.dot(R_z, np.dot( R_y, R_x ))
    return R


def ctrl_seq_proc(ctrlseq):
    case = re.split(';', ctrlseq)
    cmd = np.array([])
    for i in range(len(case)):
        cmd = np.append(cmd, case[i])
    return cmd

def TestInformationRecord(TestInfo):
    wb = Workbook()
    sheet1 = wb.active
    sheet1.title = "TestInformation"
    for i in range(len(TestInfo)):
        TestInfoLine = TestInfo[i]
        sheet1.append(TestInfoLine)

    file_pwd = os.path.dirname(os.path.abspath(__file__))
    file_pwd1 = os.path.dirname(os.path.dirname(file_pwd))
    file_store_path = os.path.dirname(file_pwd1) + "/bag/"
    # print(file_pwd)
    # print(file_store_path)
    time = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M")
    # print(time)
    TestInfo_xlsx_path = file_store_path + "TestInfo_" + time + '.xlsx'
    wb.save(TestInfo_xlsx_path)

def dict_generator(vel, x, y, z, yaw):
    """
    Attention: yaw needs to be in unit deg, not rad !!!
    """
    basic = {"vel": vel, "pose":[x, y, z], "tgt_yaw":yaw}
    return basic

# cal the vertical foot of point and line
def get_foot(point, line):
    start_x, start_y = line[0], line[1]
    end_x, end_y = line[2], line[3]
    pa_x, pa_y = point
 
    p_foot = [0, 0]
    if line[0] == line[2]:
        p_foot[0] = line[0]
        p_foot[1] = point[1]
        return p_foot
    k = (end_y - start_y) * 1.0 / (end_x - start_x)
    a = k
    b = -1.0
    c = start_y - k * start_x
    p_foot[0] = (b * b * pa_x - a * b * pa_y - a * c) / (a * a + b * b)
    p_foot[1] = (a * a * pa_y - a * b * pa_x - b * c) / (a * a + b * b)
    return p_foot

def getLinearEquation(line):
    """
    get Ax + By + C = 0(A>0)
    """
    p1x, p1y, p2x, p2y = line
    sign = 1
    a = p2y - p1y
    if a < 0:
        sign = -1
        a = sign * a
    b = sign * (p1x - p2x)
    c = sign * (p1y * p2x - p1x * p2y)
    return [a, b, c]

def judge_side(param, point):
    a, b, c = param
    D_num = a*point[0] + b*point[1] + c
    if D_num >= 0:
        # right side
        return 1
    elif D_num < 0:
        # left side
        return -1

#  计算两直线的夹角
def GetCrossAngle(line1, line2):
    [x1,y1,x2,y2]=line1
    [x3,y3,x4,y4]=line2
    arr_0 = np.array([(x2 - x1), (y2 - y1)])
    arr_1 = np.array([(x4 - x3), (y4 - y3)])
    cos_value = (float(arr_0.dot(arr_1)) / (np.sqrt(arr_0.dot(arr_0)) * np.sqrt(arr_1.dot(arr_1))))
    if cos_value>1:
        cos_value=1
    elif cos_value<-1:
        cos_value=-1
    return np.arccos(cos_value)


if __name__=="__main__":
    R = eulerAngleToMatrix([np.deg2rad(-0.69),np.deg2rad(1.84),np.deg2rad(3.14)])
    print(R)
    print(R.T)
    print(saturation(12,10))
    print(saturation(np.array([1,2,3]),10))

    CaseID = ["Real Flight case ID", 100]
    CtrlSeq = ['Control Sequence', "123;456,567"]
    FaultID = ['Fault ID', "123;456,567"]
    FaultParam = ['Fault param', "123;456,567"]
    FaultInjectInfo = ['Fault injection time', 45]
    EndInfo = ['Test end time', 123]
    TestInfo = [CaseID, CtrlSeq, FaultID, FaultParam, FaultInjectInfo, EndInfo]
    TestInformationRecord(TestInfo)
    

    