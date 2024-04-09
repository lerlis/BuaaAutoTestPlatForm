# Copyright (C) RflySim from Central South University and
# rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import imp
import PX4MavCtrlV4 as PX4MavCtrl
import time
import subprocess
import os
import sys
import json

path = os.getcwd()
jsonpath = sys.path[0] + '\db.json'
print(sys.path[0])
# 打开原json文件，读取bat
with open(jsonpath, "r",encoding='utf-8') as f:
    db_data = json.load(f)
    bat = db_data['testbat']
f.close()
# 启动HIL软件
def HIL_connect(mav):
    cmdStr = '{}//bat//{}.bat'.format(path,bat)
    # 启动HIL软件
    global child
    child = subprocess.Popen(cmdStr,shell=True,stdout=subprocess.PIPE)
    print('Starting hardware in the loop simulation software')
    time.sleep(25)
    # print('20s,启动成功')

    #开始连接
    # print('连接CopterSim')
    time.sleep(0.5)

    # 重启
    # mav.sendRebootPix(1,1000)
    # print('重启CopterSim')
    # time.sleep(20)

    mav.InitMavLoop()
    # print('初始化MAV环模式')
    time.sleep(0.5)

    mav.initOffboard()
    # print('初始化Offboard模式成功')
    time.sleep(0.5)

    mav.InitTrueDataLoop()
    time.sleep(0.5)
    # print("初始化真值监听环")

def HIL_disconnect(mav):
    mav.endMavLoop() # 此命令非常重要,如果在每次执行完不退出的话,那么下一次启动则不会再初始化MavLoop
    # print('退出MAvLoop')
    time.sleep(0.5)
    mav.EndTrueDataLoop()# 此命令非常重要,如果在每次执行完不退出的话,那么下一次启动则不会再开启监听环
    # print('退出TrueDataLoop')
    # 重启
    time.sleep(5)
    # 退出SIL
    print('Exit hardware in the loop simulation software')
    os.system('tasklist|find /i "CopterSim.exe" && taskkill /im "CopterSim.exe"')
    os.system('tasklist|find /i "QGroundControl.exe" && taskkill /f /im "QGroundControl.exe"')
    os.system('tasklist|find /i "RflySim3D.exe" && taskkill /f /im "RflySim3D.exe"')
    child.terminate()
    child.kill()
    print('All closed')
    time.sleep(5)