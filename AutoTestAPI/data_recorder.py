# Copyright (C) rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import numpy as np
from openpyxl import Workbook
# import datetime
import os
import re
# import pandas as pd


class datalogger():
    def __init__(self, caseID, UniqueIndex):
        # 测试用例记录
        self.caseID = caseID
        # 真实数据记录
        self.trueAngEular_list = np.array([0, 0, 0])  # True simulated Eular angles from CopterSim's DLL model
        self.trueVelNED_list = np.array([0, 0, 0])  # True simulated speed from CopterSim's DLL model  in NED frame
        self.truePosNED_list = np.array([0, 0, 0])  # True simulated position (related to UE4 map center) from CopterSim's DLL model
        self.trueAccB_list = np.array([0, 0, 0])  # True simulated acc from CopterSim's DLL model 
        self.trueMotorRPMs_list = np.array([0, 0, 0, 0, 0, 0, 0, 0])  # True simulated MotorRPMS from CopterSim's DLL model 
        self.trueAngRate_list = np.array([0, 0, 0])  # True simulated angular rate from CopterSim's DLL model
        self.trueAngQuatern_list = np.array([1, 0, 0, 0])  # True simulated AngQuatern from CopterSim's DLL model  
        self.truePosGPS_list = np.array([0, 0, 0])  # True simulated PosGPS from CopterSim's DLL model
        # 时间戳记录
        self.flyindex = 0  # 250Hz程序记录数据次数
        self.uavTimeStmp_list = [0]  # PX4时间戳
        self.trueTimeStmp_list = [0]  # ？
        # PX4估计数据记录
        self.uavAngEular_list = np.array([0, 0, 0])  # Estimated Eular angles from PX4
        self.uavAngRate_list = np.array([0, 0, 0])  # Estimated angular rate from PX4
        self.uavPosNED_list = np.array([0, 0, 0])  # Estimated Local Pos (related to takeoff position) from PX4 in NED frame
        self.uavVelNED_list = np.array([0, 0, 0])  # Estimated local velocity from PX4 in NED frame
        self.uavPosGPS_list = np.array([0, 0, 0])  # Estimated GPS position from PX4 in NED frame
        self.uavPosGPSHome_list = np.array([0, 0, 0])  # Estimated GPS home (takeoff) position from PX4 in NED frame
        self.uavGlobalPos_list = np.array([0, 0, 0])  # Estimated global position from PX4 that transferred to UE4 map
        # cmd指令
        self.cmd_str = ["2,1"]
        self.fault_state = 0
        self.fault_remain_flag = 0
        self.fault_state_L = [0]
        # 文件存放路径
        self.ProjectPath = os.path.dirname(os.path.dirname(__file__))
        self.DataPath = self.ProjectPath + '/Data'
        self.CaseID = caseID
        self.UniqueIndex = UniqueIndex
        self.TargetFilder = self.DataPath + '/TestCase_{}_{}'.format(self.CaseID, self.UniqueIndex)  # 获取当前测试用例的ID和目标文件夹
        self.TargetFilder_log = self.TargetFilder + '/Log'  # log文件夹路径
        self.TargetFilder_truedata = self.TargetFilder + '/TrueData'  # 用户选择的文件夹路径

    def update(self, mav, index, cmd):
        # 真实数据更新
        self.trueAngEular_list = np.row_stack((self.trueAngEular_list, np.array(mav.trueAngEular)))
        self.trueVelNED_list = np.row_stack((self.trueVelNED_list, np.array(mav.trueVelNED)))
        self.truePosNED_list = np.row_stack((self.truePosNED_list, np.array(mav.truePosNED)))
        self.trueAccB_list = np.row_stack((self.trueAccB_list, np.array(mav.trueAccB)))
        self.trueMotorRPMs_list = np.row_stack((self.trueMotorRPMs_list, np.array(mav.trueMotorRPMS)))
        self.trueAngRate_list = np.row_stack((self.trueAngRate_list, np.array(mav.trueAngRate)))
        self.trueAngQuatern_list = np.row_stack((self.trueAngQuatern_list, np.array(mav.trueAngQuatern)))
        self.truePosGPS_list = np.row_stack((self.truePosGPS_list, np.array(mav.truePosGPS)))
        # 时间更新
        self.flyindex = index
        self.uavTimeStmp_list.append(mav.uavTimeStmp)
        self.trueTimeStmp_list.append(mav.trueTimeStmp)
        # PX4估计数据更新
        self.uavAngEular_list = np.row_stack((self.uavAngEular_list, np.array(mav.uavAngEular)))
        self.uavAngRate_list = np.row_stack((self.uavAngRate_list, np.array(mav.uavAngRate)))
        self.uavPosNED_list = np.row_stack((self.uavPosNED_list, np.array(mav.uavPosNED)))
        self.uavVelNED_list = np.row_stack((self.uavVelNED_list, np.array(mav.uavVelNED)))
        self.uavPosGPS_list = np.row_stack((self.uavPosGPS_list, np.array(mav.uavPosGPS)))
        self.uavPosGPSHome_list = np.row_stack((self.uavPosGPSHome_list, np.array(mav.uavPosGPSHome)))
        self.uavGlobalPos_list = np.row_stack((self.uavGlobalPos_list, np.array(mav.uavGlobalPos)))
        # cmd 指令更新
        self.cmd_str.append(cmd)
        cmdseq = re.findall(r'-?\d+\.?[0-9]*', cmd)
        if cmdseq[0] == '2' and cmdseq[1] == '6':
            self.fault_state = 1
        if self.fault_state == 1 and (cmdseq[0] == '1' and cmdseq[1] == '1'):
            self.fault_remain_flag = 1
        if self.fault_remain_flag == 1 and (cmdseq[0] != '1' and cmdseq[1] != '1'):
            self.fault_state = 0
            self.fault_remain_flag = 0
        self.fault_state_L.append(self.fault_state)
        
    def generate_true_data(self):
        workbook = Workbook()
        sheet = workbook.active
        sheet.title = "truedataset"
        sheet.append(["index", "trueTime", "PosGPS[1]", "PosGPS[2]", "PosGPS[3]", "PosNED[1]", "PosNED[2]", "PosNED[3]", "VelNED[1]", "VelNED[2]",
            "VelNED[3]",  "AccB[1]", "AccB[2]", "AccB[3]", "AngRate[1]", "AngRate[2]", "AngRate[3]", "Eular[1]", "Eular[2]", "Eular[3]", "q[1]", 
            "q[2]", "q[3]", "q[4]", "motorRPMs[1]", "motorRPMs[2]", "motorRPMs[3]", "motorRPMs[4]", "motorRPMs[5]", "motorRPMs[6]", "motorRPMs[7]", 
            "motorRPMs[8]", "cmd", "fault_state"])
        for i in range(1, self.flyindex+1):
            temp = np.array([i-1])
            # time = np.array([self.trueTimeStmp_list[i]])
            temp = np.concatenate([temp, np.array([self.trueTimeStmp_list[i]])])
            temp = np.concatenate([temp, self.truePosGPS_list[i]])
            temp = np.concatenate([temp, self.truePosNED_list[i]])
            temp = np.concatenate([temp, self.trueVelNED_list[i]])
            temp = np.concatenate([temp, self.trueAccB_list[i]])
            temp = np.concatenate([temp, self.trueAngRate_list[i]])
            temp = np.concatenate([temp, self.trueAngEular_list[i]])
            temp = np.concatenate([temp, self.trueAngQuatern_list[i]])
            temp = np.concatenate([temp, self.trueMotorRPMs_list[i]])
            tmpl = list(temp)
            tmpl.append(self.cmd_str[i])
            tmpl.append(self.fault_state_L[i])
            sheet.append(tmpl)
        truedata_xlsxpath = self.TargetFilder_truedata + '//TrueState_data.xlsx'
        workbook.save(filename=truedata_xlsxpath)
        # data_xlsx = pd.read_excel(truedata_xlsxpath, sheet_name="truedataset")
        # truedata_csvpath = self.TargetFilder_truedata + '//Truedata_self.csv'
        # data_xlsx.to_csv(truedata_csvpath, encoding='utf-8', index=False)

    def generate_es_data(self):
        wb = Workbook()
        sh = wb.active
        sh.title = "extimatedataset"
        sh.append(["index", "uavTime", "PosGPS[1]", "PosGPS[2]", "PosGPS[3]", "PosNED[1]", "PosNED[2]", "PosNED[3]", "VelNED[1]", 
        "VelNED[2]", "VelNED[3]", "GlobalPos[1]", "GlobalPos[2]", "GlobalPos[3]", "GPSHome[1]", "GPSHome[2]", "GPSHome[3]", "Eular[1]", 
        "Eular[2]", "Eular[3]", "AngRate[1]", "AngRate[2]", "AngRate[3]", "cmd", "fault_state"])
        for i in range(1, self.flyindex+1):
            temp = np.array([i-1])
            temp = np.concatenate([temp, np.array([self.uavTimeStmp_list[i]])])
            temp = np.concatenate([temp, self.uavPosGPS_list[i]])
            temp = np.concatenate([temp, self.uavPosNED_list[i]])
            temp = np.concatenate([temp, self.uavVelNED_list[i]])
            temp = np.concatenate([temp, self.uavGlobalPos_list[i]])
            temp = np.concatenate([temp, self.uavPosGPSHome_list[i]])
            temp = np.concatenate([temp, self.uavAngEular_list[i]])
            temp = np.concatenate([temp, self.uavAngRate_list[i]])
            tmpl = list(temp)
            tmpl.append(self.cmd_str[i])
            tmpl.append(self.fault_state_L[i])
            sh.append(tmpl)
        uav_xlsxpath = self.TargetFilder_truedata + '//UAVState_data.xlsx'
        wb.save(filename=uav_xlsxpath)
        # data_xls = pd.read_excel(uav_xlsxpath, sheet_name="extimatedataset")
        # uav_csvpath = self.TargetFilder_truedata + '//uavdata.csv'
        # data_xls.to_csv(uav_csvpath, encoding='utf-8', index=False)


# if __name__ == "__main__":
#     time = datetime.datetime.now().strftime("%Y-%m-%d")
#     print(time)
#     array1 = np.array([0])
#     array2 = np.array([0, 0, 0])
#     temp = np.concatenate([array1, array2])
#     print(temp)
#     temp = np.array([1])
#     array3 = [4, 5, 6, 7, 8, 9]
#     a = np.array([array3[0]])
#     print(temp)
#     print(a)
#     b = np.concatenate([temp, a])
#     print(b)
#     cmdseq = '2,3,0,0,-20'
#     print(cmdseq)
#     cmdseq = re.findall(r'-?\d+\.?[0-9]*', cmdseq)  # ['2', '3', '0', '0', '-20']
#     print(cmdseq)
#     ProjectPath = os.path.dirname(os.path.dirname(__file__))
#     print(ProjectPath)
