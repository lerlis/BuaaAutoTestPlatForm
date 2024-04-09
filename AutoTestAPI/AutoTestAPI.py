# Copyright (C) RflySim from Central South University and
# rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import PX4MavCtrlV4 as PX4MavCtrl
import numpy as np
import re
import time
import Off_ctrl_connect_copter
import Health_ass
import mavdb
import command
import cv2.cv2 as cv2
from data_recorder import datalogger
from sense_direction import sense_direction
from sense_circle import sense_circle

STATE_TGT_WP_ONE = 4


def DoCmd(ctrlseq):
    cmdseq = ctrlseq  # '2,3,0,0,-20'
    cmdseq = re.findall(r'-?\d+\.?[0-9]*', cmdseq)  # ['2', '3', '0', '0', '-20']
    cmdCID = cmdseq[0]
    if cmdCID in CFID.CID:
        FID = CFID.FIDPro(cmdCID)
        # 有参数输入
        if len(cmdseq) > 2:
            # 提取参数
            param = cmdseq[2:len(cmdseq)]
            param = [float(val) for val in param]
            FID[cmdseq[1]](param)
        else:
            FID[cmdseq[1]]()
    else:
        print('Command input error, please re-enter')


mav_db = mavdb.mavdb()  # 创建mavdb对象
caselist, unqindex = mav_db.get_fault_case_ID()  # 获取测试用例ID列表

caseindex = 0
print('caselist_length:', len(caselist))

# 开始循环测试----------------------------------------------
while True:
    # 根据json文件获取
    if caseindex >= len(caselist):
        print('All case test finish!')
        break

    CaseID = caselist[caseindex]
    UniqueIndex = unqindex[caseindex]

    # 初始化连接-------------------------------------------------
    # 启动硬件在环仿真
    mav = PX4MavCtrl.PX4MavCtrler(UniqueIndex, 20100)
    Off_ctrl_connect_copter.HIL_connect(mav)

    # 初始化数据处理接口对象
    DataObj = mavdb.DataAPI(CaseID, UniqueIndex)

    # 记录数据启动
    datarecoder = datalogger(CaseID, UniqueIndex)

    # 初始化吊舱视觉对象
    # pod = OtherFaultAPI.PodFault()

    m = 2.0843  # 整机重量

    # 飞行数据变量声明
    mean_arr_v = np.array([0, 0, 0])  # 均值数组，用于存放每组的速度均值
    mean_arr_ang = np.array([0, 0, 0])  # 均值数组，用于存放每组的角速度均值
    mean_arr_acc = np.array([0, 0, 0])  # 均值数组，用于存放每组的加速度均值
    mean_arr_eular = np.array([0, 0, 0])  # 均值数组，用于存放每组的欧拉角均值
    mean_arr_pos = np.array([0, 0, 0])  # 均值数组，用于存放每组的位置均值
    mean_arr_motor = np.array([0, 0, 0, 0, 0, 0, 0, 0])  # 均值数组，用于存放每组的电机均值
    fall_vel = 0  # 坠机速度
    fall_energy = 0  # 坠机动能
    InjectVel = 0  # 故障注入时刻速度
    InjectPos = 0  # 故障注入时刻位置

    # 索引变量
    fly_index = 0  # 总的飞行数据索引
    record_index = 0  # 开始记录索引
    record_flag = 0
    record_time = 0
    break_index = 0  # 退出测试索引
    break_flag = 0
    break_time = 0
    fault_inject_index = 0  # 故障注入索引
    fault_inject_flag = 0
    fault_inject_time = 0
    fall_index = 0  # 坠机索引
    fall_flag = 0
    fall_time = 0
    land_index = 0  # 降落索引
    land_flag = 0
    land_time = 0

    # Initialize sense direction
    sd_ctrl = sense_direction()
    sc_ctrl = sense_circle()

    wpL_state = 1
    wpL_state_one = 0
    circle_info_state = 0

    # 评估参数
    Fault_risk = 0
    Fault_rank = 0
    AssessmentCount = 0  # 单个用例评估次数（指不同阶段）

    # 测试状态参数
    isArmerror = 0

    # 数据库参数
    ID = 0
    FaultTestType = np.array([])
    FaultParameters = np.array([])

    # 测试信息
    TestCaseID = []
    CtrlSeq = []
    FaultID = []
    FaultParam = []
    FaultInjectinfo = []
    Endinfo = []
    Otherinfo = []
    Otherinfo2 = []

    # 启动时间和结束时间(启动后解锁，以防止地面站不开始计时)
    start_time = time.time()
    end_time = time.time()

    # 初始化类库
    CFID = command.CmdCtrl(mav, start_time)
    CID1obj = CFID.CID1obj
    CID2obj = CFID.CID2obj

    mav.SendMavArm(1)
    print('****************************CaseID {} test*****************************'.format(CaseID))
    print('Sim start')

    lastTime = time.time()

    # 控制序列参数处理
    i = 0
    # cmd = CmdPro(case) # ['2,1' '1,1,5' '2,3,0,0,-20']
    cmd = mav_db.ctrl_seq_pro(CaseID)
    print('cmd', cmd)
    seqlen = len(cmd)

    takeoff_done = False
    first_flag = 1

    while True:
        # 250HZ接收数据
        lastTime = lastTime + (1.0/250)
        sleepTime = lastTime - time.time()
        if sleepTime > 0:
            time.sleep(sleepTime)
        else:
            lastTime = time.time()
        
        # print(mav.trueSimulinkData) # 查看实时模型数据
        if mav_db.isvision == 1:
            # img_show()
            pass

        # if CID2obj.isInject == 1 and CID2obj.PodFault == 1:
        #     pod.Podfault(CID2obj.silInt[0])
        # 解锁指令发出后开始记录数据

        if CID2obj.isArm == 1:
            # 用于方差分析的数据，速度和角速度,需将其转化为数组,否则数据会一直变化
            vel = np.array(mav.trueVelNED)
            angrate = np.array(mav.trueAngRate)
            aacc = np.array(mav.trueAccB)
            mmotor = np.array(mav.trueMotorRPMS)
            eular = np.array(mav.trueAngEular)
            pos = np.array(mav.truePosNED)
            fly_index = fly_index + 1
            mean_arr_v = np.row_stack((mean_arr_v, vel))  # 将其加入速度均值数组中
            mean_arr_ang = np.row_stack((mean_arr_ang, angrate))  # 将其加入角速度均值数组中
            mean_arr_acc = np.row_stack((mean_arr_acc, aacc))  # 将其加入加速度均值数组中
            mean_arr_eular = np.row_stack((mean_arr_eular, eular))  # 将其加入加速度均值数组中
            mean_arr_motor = np.row_stack((mean_arr_motor, mmotor))  # 将其加入电机均值数组中
            mean_arr_pos = np.row_stack((mean_arr_pos, pos))  # 将其加入电机均值数组中
            # 用于产生数据表格，积累数据
            datarecoder.update(mav, fly_index, cmd[i])

        # 处理指令序列
        if takeoff_done or first_flag == 1:
            DoCmd(cmd[i])
            first_flag = 0
        error = mav.set_height - mav.mav_height
        kp = 1.1
        vz_err = kp * error
        back = CID2obj.returnvalue

        if back == 0:
            pass
        else:
            if back[0] == 1:
                param = back[1]
                if not takeoff_done:
                    mav.SendVelFLU(0, 0, param[1])
                    takeoff_done = mav.mav_height > param[2]*0.95
                    if takeoff_done:
                        mav.init_yaw = mav.mav_yaw_g
                        # Rotation Matrix earth2init_pose
                        mav.R_ei = np.array([
                            [np.cos(mav.init_yaw), -np.sin(mav.init_yaw), 0],
                            [np.sin(mav.init_yaw),  np.cos(mav.init_yaw), 0],
                            [0, 0, 1]
                        ])
                        mav.R_ei = mav.R_ei.T
                else:
                    mav.SendVelFLU(0, 0, vz_err, 0)
            elif back[0] == 9:
                waypoints = back[1]
                num_wp = len(waypoints) - 1
                last_wp = waypoints[wpL_state-1]
                wp = waypoints[wpL_state]

                sd_ctrl.set_tgt_wp(wp, last_wp, mav.init_yaw, mav.R_ei)
                yaw = mav.mav_yaw  # current yaw (corresponding to takeoff)
                R_be = mav.mav_Rbe
                sd_ctrl.update_kinematics(yaw, R_be)
                v_cmd, yaw_rate_cmd = sd_ctrl.sense_direction_update(mav.mav_pos)

                tgt_pose = wp["pose"]
                tgt_yaw = wp["tgt_yaw"]
                mav.set_height = tgt_pose[2]

                if wpL_state_one == STATE_TGT_WP_ONE:
                    mav.SendVelFLU(0, 0, vz_err, 0)
                    # print("Current velocity command is {:.2f}, {:.2f}, {:.2f}, {:.2f} !".format(0, 0, vz_err, 0))
                else:
                    mav.SendVelFLU(v_cmd[0], v_cmd[1], vz_err, yaw_rate_cmd)
                    # print("Current velocity command is {:.2f}, {:.2f}, {:.2f}, {:.2f} !!!".format(v_cmd[0], v_cmd[1], vz_err, yaw_rate_cmd))
                pos_init_flu = mav.R_ei.dot(mav.mav_pos)
                check_dis = np.linalg.norm(tgt_pose[0:2] - pos_init_flu[0:2])  # 放弃对高度的检查,防止在故障失去高度的情况下失去控制
                if check_dis < 1.1 and (wpL_state_one != STATE_TGT_WP_ONE):
                    wpL_state = wpL_state + 1
                    if wpL_state > num_wp:
                        wpL_state = 1
                        # 循环飞行，将最后一个航路点设置为第一个航路点的前置航路点
                        back[1][0] = back[1][num_wp]
                        if num_wp == 1:  # 只有一个目标航路点的特殊情况处理
                            wpL_state_one = STATE_TGT_WP_ONE
                    sd_ctrl.reset()
                    # for a in range(10):
                    #     print("Changed!!!!!!!")
            elif back[0] == 10:
                # Acce and Dece vel process
                param = back[1]
                now_time = time.time()
                if (now_time - param[2]) < param[1]:
                    vx_s = mav.set_forward_vel + (now_time - param[2]) * param[0]
                else:
                    vx_s = mav.set_forward_vel + param[1] * param[0]
                mav.SendVelFLU(vx=vx_s, vy=0, vz=vz_err, yawrate=0)
            elif back[0] == 11:
                # Fly circle with center
                param = back[1]
                circle_pos_flu = param[4:7]
                basic_yaw_rate = param[3]
                # print('basic yaw rate:', basic_yaw_rate)
                yaw = mav.mav_yaw  # current yaw (corresponding to takeoff)
                # print("current_yaw:", yaw)
                R_be = mav.mav_Rbe
                R_ei = mav.R_ei
                if circle_info_state == 0:
                    sc_ctrl.get_circle_info(circle_pos_flu, yaw)
                    circle_info_state = 1
                sc_ctrl.update_kinematics(yaw, R_be, R_ei)
                v_cmd, yaw_rate_cmd = sc_ctrl.update(mav.mav_pos, param, mav.init_yaw)
                adj_yaw = basic_yaw_rate + yaw_rate_cmd
                # print('Actual yaw command:', adj_yaw)
                mav.SendVelFLU(v_cmd[0], v_cmd[1], vz_err, adj_yaw)
                # print("Current velocity command is {:.2f}, {:.2f}, {:.2f}, {:.2f} !!!".format(v_cmd[0], v_cmd[1], v_cmd[2], yaw_rate_cmd))

        # 如果完成一个指令序列，则处理下一个指令
        if re.findall(r'-?\d+\.?[0-9]*', cmd[i])[0] == '1' and CID1obj.isDone == 1 or re.findall(r'-?\d+\.?[0-9]*', cmd[i])[0] == '2' and CID2obj.isDone == 1 and takeoff_done:
            i = i + 1
        
        if CID2obj.isRecord == 1 and record_flag == 0:
            record_index = fly_index  # 记录开始记录时刻索引
            record_time = round(time.time() - start_time)
            record_flag = 1
        
        if CID2obj.isInject == 1 and fault_inject_flag == 0:
            fault_inject_index = fly_index  # 记录故障注入时刻索引
            fault_inject_time = round(time.time() - start_time)
            InjectVel = np.array(mav.trueVelNED)
            InjectPos = np.array(mav.truePosNED)
            fault_inject_flag = 1
        
        if CID2obj.LandFlag == 1 and land_flag == 0:
            land_index = fly_index  # 记录降落时刻索引
            land_time = round(time.time() - start_time)
            land_flag = 1

        if i >= seqlen and break_flag == 0:
            break_index = fly_index  # 记录结束时刻索引
            break_time = round(time.time() - start_time)
            break_flag = 1
            print('CaseID {} test completed'.format(CaseID))
            end_time = time.time()
            CID2obj.stopflag = 1
            break
        
        # 坠地判断，落地速度大于4认为坠机
        if abs(np.array(mav.truePosNED[2])) < 1.2 and fall_flag == 0 and abs(np.array(mav.trueVelNED[2])) > 3.5:
            fall_time = round(time.time() - start_time)
            fall_index = fly_index
            fall_flag = 1
            fall_vel = round(np.max(mean_arr_v), 2)  # 保留两位小数
            fall_energy = round(0.5*m*(fall_vel**2), 2)  # 保留两位小数
            print("{}s,Crash!".format(fall_time))
            mav.SendMavArm(0)

        # # 如果解锁异常，退出测试，重新开始新的测试
        # if mav.isArmerror == 1:
        #     isArmerror = 1
        #     break
    
    # ---------------------------------------------------------------------------安全评估API--------------------------------------------------------------------------------------
    if isArmerror == 0:
        if CID2obj.isRecord == 1:
            # 求1s的数据个数
            one_num = round(len(mean_arr_v)/(end_time - start_time))
            if fall_flag == 1:
                # 坠机评估
                Health_ass.Fall_rank(fall_energy)
                Fault_risk = Health_ass.Sys_score
                Fault_rank = Health_ass.Sys_tag
                # 未坠机评估
            else:
                Health_ass.Fault_inject_Allan(record_index, break_index, fault_inject_index, land_index, mean_arr_ang, mean_arr_v, one_num, cmd)
                Fault_risk = Health_ass.sys_weight_score
                Fault_rank = Health_ass.Rate_rank

            # -------------------------------------------------------------------数据库处理-------------------------------------------------------------------------------------------
            # 1、判断是否为已测试过的用例，如已测试过，则删除原结果纪录，重新添加
            mav_db.repeat_case_pro(CaseID)
            # 2、数据提取
            ID = CaseID
            for k in range(len(cmd)):
                pro = re.findall(r'-?\d+\.?[0-9]*', cmd[k])  # ['2', '3', '0', '0', '-20']
                if pro[1] == '6':
                    # 提取参数
                    param = pro[2:len(pro)]
                    param = [float(val) for val in param]
                    for j in range(len(param)):
                        if param[j] >= 123450:
                            FaultTestType = np.append(FaultTestType, param[j])
                        else:
                            FaultParameters = np.append(FaultParameters, param[j])
            
            # 3、添加到结果库
            FaultTestType = str(FaultTestType)  # sqlite中要转化成字符串，负责会乱码
            FaultParameters = str(FaultParameters)  # sqlite中要转化成字符串，负责会乱码
            result_data = [ID, FaultTestType, FaultParameters, 'Finished', 'Fault risk:{} Fault level:{}'.format(Fault_risk, Fault_rank)]
            mav_db.test_result_pro(result_data)
            # 4、更改用例库测试状态
            mav_db.fault_case_pro(CaseID)

            # 5、生成数据
            datarecoder.generate_true_data()
            datarecoder.generate_es_data()

            # -------------------------------------------------------------------JSON处理-------------------------------------------------------------------------------------------
            # 更改json的测试状态信息
            mav_db.json_pro(CaseID)
        
        time.sleep(5)
        print('Sim end')
        # 退出HIL
        Off_ctrl_connect_copter.HIL_disconnect(mav)
        caseindex += 1
    else:
        # 退出仿真，重新连接，继续此测试用例
        print('Armed exception,retest!')
        time.sleep(5)
        print('Sim end')
        Off_ctrl_connect_copter.HIL_disconnect(mav)
    
    time.sleep(5)
    if mav_db.isvision == 1:
        cv2.destroyAllWindows() 
    # ---------------------------------------------------------------------------数据处理------------------------------------------------------------------------------
    # 1)生成指定文件夹并赋值log文件到对应目录并转换成csv
    print("Start data processing")
    DataObj.LogDataExtra()
    
    # 2)收集真值数据 使用Datarecorder代替了
    # DataObj.TruedataRecord(mean_arr_v, mean_arr_ang, mean_arr_pos)
    # 3)收集本次测试信息
    one_num = round(len(mean_arr_v)/(end_time - start_time))
    TestCaseID = ["Case ID", CaseID]
    CtrlSeq = ['Control Sequence', str(cmd)]
    FaultID = ['Fault ID', str(CID2obj.FaultID)]
    FaultParam = ['Fault Parameter', str(CID2obj.FaultParam)]
    FaultInjectinfo = ['Fault injection time', fault_inject_time]
    Endinfo = ['Test end time', break_time]
    Otherinfo = ['Data collected Frequency', one_num]
    Otherinfo2 = ['Data num', len(mean_arr_v)]
    TestInfo = [TestCaseID, CtrlSeq, FaultID, FaultParam, FaultInjectinfo, Endinfo, Otherinfo, Otherinfo2]
    DataObj.TestInformationRecord(TestInfo)
    print("Data processing Finished")
    # time.sleep(5)
    # DataObj.TLogDataExtra()
    if CID2obj.isRecord == 0:
        caseindex += 1
