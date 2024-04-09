# Copyright (C) RflySim from Central South University and
# rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import PX4MavCtrlV4 as PX4MavCtrl
import time
import re
import numpy as np
import threading
# 结束线程的函数
import inspect
import ctypes

from utils import dict_generator


class Sleep:
    def __init__(self, mav, whole_program_start_time):
        self.CID = 1
        self.mav = mav
        self.isDone = 0  # 任务完成标志
        self.WaitFlag = 0
        self.WaitResetFlag = 0
        self.start_time = 0
        self.wp_start_time = whole_program_start_time
    
    def Wait(self, times):  # 这种编程方式在等待时不会卡在一处等到指定的时间退出，而是在循环中一直运行。便于实时数据的记录 # ID = 1
        self.isDone = 0
        if self.WaitFlag == 0:
            print('wait {}s'.format(times[0]))
            self.start_time = time.time() + times[0]
            self.WaitFlag = 1
    
        if self.start_time - time.time() < 0: 
            self.isDone = 1
            # 等待任务完成后重新置WaitFlag为0
            self.WaitFlag = 0
        # Change flight mode
        self.mav.flight_status_param[0] = 1
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])
        
 
    def WaitReset(self,pos): # 等待复位函数 # ID = 2
        self.isDone = 0
        if self.WaitResetFlag == 0:
            print('wait reset')
            self.WaitResetFlag = 1

        if abs(self.mav.truePosNED[0] - pos[0]) < 1 and abs(self.mav.truePosNED[1] - pos[1]) < 1 and abs(self.mav.truePosNED[2] - pos[2]) < 1:
            # print('复位成功')
            self.isDone = 1
            # 复位成功后重置WaitResetFlag为0
            self.WaitResetFlag = 0
        # Change flight mode
        self.mav.flight_status_param[0] = 2
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def pri2(self):
        print('112')


class Command:
    def __init__(self, mav, whole_program_start_time):
        self.CID = 2
        self.mav = mav
        self.wp_start_time = whole_program_start_time
        self.isArm = 0 # 解锁标志(解锁意味着开始记录数据)
        self.isDone = 0 # 任务完成标志
        self.LandFlag = 0
        self.LandFlagtag = 0
        # 初始化故障注入参数
        self.silInt = np.zeros(8).astype(int).tolist()
        self.silFloats = np.zeros(20).astype(float).tolist()
        self.isRecord = 0
        self.isInject = 0
        self.PodFault = 0
        self.FaultID = np.array([])
        self.FaultParam = np.array([])
        self.ModelFault = 0
        self.OtherFault = 0
        self.phase = True
        # return to main.py
        self.returnvalue = 0
        # flag to stop cyclicity fault
        self.cycflag = 0
        self.stopflag = 0
        
    def Arm2takeoff(self, param):  # ID = 1
        """
        param[0]: time interval between armed and takeoff
        param[1]: take off vz
        param[2]: take off h
        """
        self.isDone = 0
        self.mav.SendMavArm(1)
        print('Armed')
        time.sleep(param[0])
        self.isArm = 1
        self.isRecord = 1  # 解锁之后开始收集数据
        print("takeoff pre task OK")
        self.mav.mav_yaw_offset = self.mav.mav_yaw
        self.mav.mav_pos_offset = self.mav.mav_pos
        self.mav.set_height = param[2]
        back = [1]
        back.append(param)
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 1
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def DisArm(self):  # ID = 2
        self.isDone = 0
        self.mav.SendMavArm(0)
        print('DisArmed')
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 2
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def FlyPos(self,pos): # ID = 3
        self.isDone = 0
        self.mav.SendMavArm(1)
        self.mav.SendPosENU(pos[0],pos[1],pos[2])
        print('Send Pos {}'.format(pos))
        back = [3]
        back.append(pos)
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 3
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def FlyVel(self,vel):  # ID = 4
        self.isDone = 0
        self.mav.SendVelFLU(vel[0],vel[1],vel[2])
        print('Send Vel {}'.format(vel))
        self.mav.set_forward_vel = vel[0]
        back = [4]
        back.append(vel)
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 4
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def Land(self): # ID = 5
        self.isDone = 0
        self.LandFlag = 1
        if self.LandFlagtag == 0:
            self.mav.SendVelNED(0,0,2)
            print('Start Landing')
            self.LandFlagtag = 1
        if abs(self.mav.truePosNED[2]) < 1.5:
            print('Landed')
            self.isDone = 1
            # 复位成功后重置LandFlagtag为0
            self.LandFlagtag = 0
        # Change flight mode
        self.mav.flight_status_param[1] = 5
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])
    
    def FaultInject(self,param): # ID = 6
        self.isDone = 0
        inInts = np.array([])
        inFloats = np.array([])
        IntRecord = 0
        for i in range(len(param)):
            if param[i] >= 123450 and param[i] <= 123451 or param[i] == 123454 or param[i] >= 123457 and param[i] <= 123459 or param[i] == 123544:
                # self.ModelFault = 1
                if not IntRecord:
                    inInts = np.array([param[i], param[i]])
                    IntRecord = 1
            elif param[i] >= 123452 and param[i] <= 123456:
                if not IntRecord:
                    inInts = np.array([param[i], param[i], param[i], param[i]])
                    IntRecord = 1
            elif param[i] >= 123540 and param[i] <= 123543 or param[i] >= 123545 and param[i] <= 123548:
                if not IntRecord:
                    inInts = np.array([param[i]])
                    IntRecord = 1
            # elif param[i] >= 123549 and param[i] <= 125341:  # 其他故障：Pod故障
            #     inInts = np.append(inInts, param[i])
            #     # self.PodFault = 1
            else:
                inFloats = np.append(inFloats, param[i])
      
        for i in range(len(inInts)):
            self.silInt[i] = inInts[i].astype(int)
        for i in range(len(inFloats)):
            self.silFloats[i] = inFloats[i].astype(np.double)

        f_control = [0]*16
        f_control[0] = self.mav.Test_ID
        if self.silInt[0] <= 123456:
            for i in range(15):
                f_control[i+1] = float(self.silFloats[i+1])
        else:
            for i in range(15):
                f_control[i+1] = float(self.silFloats[i])
        print('Start Inject Fault')
        # motor fault process
        if inInts[0] == 123450 or inInts[0] == 123451:
            if inFloats[0] > 10:  # cyclicity fault
                self.start_cyclicity_fault()
            elif inFloats[0] == 1:
                self.silFloats = self.silFloats[1:]
                self.silFloats.append(float(0))
                self.mav.sendSILIntFloat(self.silInt,self.silFloats)
                self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], inFloats[0], f_control)
                print(self.silInt, self.silFloats)
                self.mav.SendMavCmdLong(183,999,999,999,999,999,999,999)
            elif inFloats[0] == 2:
                self.start_fault_thread()
        else:
            self.mav.sendSILIntFloat(self.silInt,self.silFloats)
            self.mav.SendMavCmdLong(183,999,999,999,999,999,999,999)
            if self.silInt[0] <= 123456:
                self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], inFloats[0], f_control)
            else:
                self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], 0, f_control)
        # self.FaultID = self.silInt[0]
        self.FaultID = np.concatenate([self.FaultID, [self.silInt[0]]])
        # self.FaultParam = inFloats
        self.FaultParam = np.concatenate([self.FaultParam, inFloats])
        self.isDone = 1
        self.isInject = 1

    def FlyYaw(self, yaw_rad): # ID = 7
        self.isDone = 0
        yaw_rad = np.deg2rad(yaw_rad)
        self.mav.SendVelFLU(vx=0,vy=0,vz=0,yawrate=yaw_rad) # The actual yaw rad in ENU
        print('Send yaw rad {}'.format(yaw_rad))
        back = [7]
        back.append(yaw_rad)
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 7
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def FlyCircle(self, param): # ID = 8
        """
        param[0]: radius, param[1]: linear vel, param[2]: clockwise(0:clockwise, 1:anti-clockwise)
        """
        self.isDone = 0
        L = 2*np.pi*param[0]
        t = L / param[1]
        cir_yaw_rate = np.deg2rad(360 / t)
        if param[2] == 0: # clockwise
            self.mav.SendVelFLU(vx=param[1],vy=0,vz=0,yawrate=-cir_yaw_rate)
            # self.px4_control.moveByVelocityYawrateBodyFrame(vx=param[1], vy=0, vz=0, yaw_rate=-cir_yaw_rate)
            # back.append([param[1], -cir_yaw_rate])
            # self.returnvalue = back
            print('Send circle param: {}'.format(param))
        elif param[2] == 1: #anti-clockwise
            self.mav.SendVelFLU(vx=param[1],vy=0,vz=0,yawrate=cir_yaw_rate)
            # self.px4_control.moveByVelocityYawrateBodyFrame(vx=param[1], vy=0, vz=0, yaw_rate=cir_yaw_rate)
            # back.append([param[1], cir_yaw_rate])
            # self.returnvalue = back
            print('Send circle param: {}'.format(param))
        back = [8]
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 8
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def FlyLongTrack(self, param): # ID = 9
        """
        param[0]: vel1, param[1-4]: pos1 & tgt_yaw1, etc... param[0+5i - 4+5i] ...
        """
        self.isDone = 0
        init_wp = {
            "vel":0,
            "pose":np.array([0, 0, self.mav.set_height]),
            "tgt_yaw":0 # tgt_yaw means the offset between init takeoff pose and target, not in world frame ENU, but in FLU
        }
        wpL = []
        wpL.append(init_wp)
        length_param = len(param)
        for i in range((length_param // 5)):
            sigle_dict = dict_generator(param[0+5*i], param[1+5*i], param[2+5*i], param[3+5*i], param[4+5*i])
            wpL.append(sigle_dict)
        back = [9]
        back.append(wpL)
        start_time = time.time()
        back.append(start_time)
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 9
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def AcceAndDece(self, param): # ID = 10
        """
        param[0]: accelaration, param[1]: time, param[2]: direction
        """
        self.isDone = 0
        task_begin_time = time.time()
        back = [10]
        if param[2] == 0:  # Acceleration
            back.append([param[0], param[1], task_begin_time])
        elif param[2] == 1:  # Deceleration
            back.append([-param[0], param[1], task_begin_time])
        self.returnvalue = back
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 10
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])
    
    def FlyCircleCenter(self, param): # ID = 11
        """
        param[0]: radius, param[1]: linear vel, param[2]: clockwise(0:clockwise, 1:anti-clockwise)
        param[3-5]: tgt_pose of circle(x, y, z)
        """
        self.isDone = 0
        L = 2*np.pi*param[0]
        t = L / param[1]
        cir_yaw_rate = np.deg2rad(360 / t)
        back = [11]
        if param[2] == 0:
            back.append([param[0], param[1], param[2], -cir_yaw_rate, param[3], param[4], param[5]])
        elif param[2] == 1:
            back.append([param[0], param[1], param[2], cir_yaw_rate, param[3], param[4], param[5]])
        self.returnvalue = back
        print('Send circle param: {}'.format(param))
        self.isDone = 1
        # Change flight mode
        self.mav.flight_status_param[1] = 11
        self.mav.SendOffbInformation(float(time.time() - self.wp_start_time), self.mav.flight_status_param[0], self.mav.flight_status_param[1])

    def start_fault_thread(self):
        self.cmd_fault_th = threading.Thread(target=self.continue_fault_loop, args=())
        self.cmd_fault_th.start()
        # time.sleep(1)
        print("start construct continous fault target")

    def continue_fault_loop(self): # 参数连续变化类型故障
        # send data process
        c_mode = self.silFloats[0]
        self.silFloats = self.silFloats[1:]
        self.silFloats.append(float(0))
        f_control = [0]*16
        f_control[0] = self.mav.Test_ID
        n_f_control = [0]*16
        n_f_control[0] = self.mav.Test_ID
        fault_vec = np.zeros(20).astype(np.double)
        non_fault_vec = np.zeros(20).astype(np.double)
        non_silInt = np.zeros(8).astype(int)
        start_time = time.time()
        Time_list = [self.silFloats[2], self.silFloats[5], self.silFloats[8], self.silFloats[11]]
        end_time = start_time + max(Time_list)
        self.mav.SendMavCmdLong(183,999,999,999,999,999,999,999)
        while (time.time() < end_time):
            for i in range(4):
                fault_vec[i] = calFaultExactNum(self.silFloats[3*i], self.silFloats[1+3*i], self.silFloats[2+3*i], start_time)
                f_control[i+1] = fault_vec[i]
            if self.cycflag == 0:
                self.mav.sendSILIntFloat(self.silInt,fault_vec)
                self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], c_mode, f_control)
            elif self.cycflag == 1:
                self.mav.sendSILIntFloat(non_silInt,non_fault_vec)
                self.mav.SendFaultInformation(0, self.silInt[0], c_mode, n_f_control)
            time.sleep(0.01)
        self.stop_thread(self.cmd_fault_th.ident)

    def stop_thread(self, thread_id):
        _async_raise(thread_id, SystemExit)
        time.sleep(1)
        print("a thread is dead")

    def start_cyclicity_fault(self):
        self.cmd_cyclicity_fault_th = threading.Thread(target=self.cyclicity_fault_loop, args=())
        self.cmd_cyclicity_fault_th.start()
        # time.sleep(1)
        print("start construct cyclicity fault target")

    def cyclicity_fault_loop(self):  # 周期性故障注入
        # send data process
        c_mode = self.silFloats[0] - 10
        self.silFloats = self.silFloats[1:]
        self.silFloats.append(float(0))
        f_control = [0]*16
        f_control[0] = self.mav.Test_ID
        n_f_control = [0]*16
        n_f_control[0] = self.mav.Test_ID
        CTime = self.silFloats[0]
        Duration = self.silFloats[1]
        fault_vec = np.zeros(20).astype(np.double)
        non_fault_vec = np.zeros(20).astype(np.double)
        non_silInt = np.zeros(8).astype(int)
        for i in range(17):
            fault_vec[i] = self.silFloats[2+i]
        for i in range(15):
            f_control[i+1] = fault_vec[i]
        self.mav.sendSILIntFloat(self.silInt,fault_vec)
        self.mav.SendMavCmdLong(183,999,999,999,999,999,999,999)
        self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], c_mode, f_control)
        start_time = time.time()
        while (not self.stopflag):
            if self.phase == True:
                if self.cycflag == 0:
                    self.mav.sendSILIntFloat(self.silInt,fault_vec)
                    self.mav.SendFaultInformation(self.mav.Test_ID, self.silInt[0], c_mode, f_control)
                elif self.cycflag == 1:
                    self.mav.sendSILIntFloat(non_silInt,non_fault_vec)
                    self.mav.SendFaultInformation(0, self.silInt[0], c_mode, n_f_control)
            elif self.phase == False:
                self.mav.sendSILIntFloat(non_silInt,non_fault_vec)
                self.mav.SendFaultInformation(0, self.silInt[0], c_mode, n_f_control)
            if ((time.time() - start_time) > CTime and self.phase == False) :
                start_time = time.time()
                self.phase = True
                # print("Change Injection mode!!!, now phase is {}".format(self.phase))
            if ((time.time() - start_time) > Duration and self.phase == True):
                self.phase = False  # Only fools could make this mistake!!!!!!!!!!!!!!
                # print("Change Injection mode!!!, now phase is {}".format(self.phase))
            time.sleep(0.05)
        self.mav.sendSILIntFloat(non_silInt,non_fault_vec)
        self.mav.SendFaultInformation(0, self.silInt[0], c_mode, n_f_control)
        self.stop_thread(self.cmd_cyclicity_fault_th.ident)

        

# 获取控制函数
class CmdCtrl:
    def __init__(self,mav, start_time):
        self.mav = mav
        self.start_time = start_time
        self.CID = {
        '1':Sleep(mav, start_time),
        '2':Command(mav, start_time)
        }
        self.CID1obj = self.CID['1']
        self.CID2obj = self.CID['2']
        self.FID = 0

    # 获取控制函数
    def FIDPro(self,cmdCID):
        if cmdCID == '1':
            self.FID = {
                '1':self.CID1obj.Wait,
                '2':self.CID1obj.WaitReset
            }
        elif cmdCID == '2':
            self.FID = {
                '1':self.CID2obj.Arm2takeoff,
                '2':self.CID2obj.DisArm,
                '3':self.CID2obj.FlyPos,
                '4':self.CID2obj.FlyVel,
                '5':self.CID2obj.Land,
                '6':self.CID2obj.FaultInject,
                '7':self.CID2obj.FlyYaw,
                '8':self.CID2obj.FlyCircle,
                '9':self.CID2obj.FlyLongTrack,
                '10':self.CID2obj.AcceAndDece,
                '11':self.CID2obj.FlyCircleCenter
            }
        return self.FID

# 用于结束线程的函数
def _async_raise(tid, exctype):
    
    if not inspect.isclass(exctype):
        raise TypeError("Only types can be raised (not instances)")
    res = ctypes.pythonapi.PyThreadState_SetAsyncExc(ctypes.c_long(tid), ctypes.py_object(exctype))
    if res == 0:
        raise ValueError("invalid thread id")
    elif res != 1:
        ctypes.pythonapi.PyThreadState_SetAsyncExc(tid, None)
        raise SystemError("PyThreadState_SetAsyncExc failed")  
        

def calFaultExactNum(alpha1, alpha2, time_interval, begin_time):
    """
    A simply linear function here:
    At begin_time, fault_param = alpha1; and in the end, fault_param = alpha2
    """
    now_time = time.time()
    if now_time < (begin_time + time_interval):
        k = (alpha2 - alpha1) / time_interval
        param = k * (now_time - begin_time) + alpha1
        return param
    else:
        return alpha2
