# Copyright (C) rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import json
import numpy as np
import sys


# Parameters setting
Path = "E:/PX4PSP"
Runbat = "FaultModelSITL"
Faulttype = 123549
FaultMode = 0
Flight_mode = 5
MODE_flight = 0  # discard
fault_para_num = 1
Para_min = 0.61
Para_max = 1.0
Step_Length = 0.01
Fault_keep_time = 15
Continues_fault_time = [50,50,50,50]
C_Time = 6
Time_Effect = 0.5
Sensor_bias = [0, 0, 0]

# MODE
BeginIndex = 0
Changed_default_id = 200
TotalIndex = 0
# MODE = 1, 生成新的db文件
# MODE = 2, 修改现有db文件
MODE_db = 1


def basic_generator(num, path, bat, vis_mode):
    basic_js = {"faultcase": [], "testdata": {}, "testcase": num, "PlatFormPath": path, "testbat": bat, "Vision": vis_mode}
    return basic_js


def fault_case_generator(faulttype, flight_mode, fault_para_num, para_min, para_max, step_length, bat):
    case = []
    subsys_name = subsystem_from_faulttype(faulttype)
    fault_name = str(faulttype)
    step = int((para_max - para_min) / step_length)
    default_id = Changed_default_id
    if fault_para_num == 1:
        for i in range(step + 1):
            caseid = caseID_generator(bat, flight_mode, faulttype, default_id)
            default_id += 1
            para = round(para_min + step_length * i, 4)
            cmd_flight = cmd_from_flight_fault(flight_mode, faulttype, fault_para_num, para)
            cmd = "2,1,0.5,1,15;1,1,5;" + cmd_flight + "1,1," + str(Fault_keep_time)
            js = {"CaseID": default_id, "Subsystem": subsys_name, "FaultType": fault_name, "ControlSequence": cmd, "InterestedLog": {}, "TestStatus": "UnFinished", "UniqueIndex": caseid}
            case.append(js)
        return case
    elif fault_para_num == 2:
        for j in range(step + 1):
            para1 = para_min + step_length * j
            for i in range(step + 1):
                caseid = caseID_generator(bat, flight_mode, faulttype, default_id)
                default_id += 1
                para2 = para_min + step_length * i
                para = [round(para1, 4), round(para2, 4)]
                cmd_flight = cmd_from_flight_fault(flight_mode, faulttype, fault_para_num, para)
                cmd = "2,1,0.5,1,15;1,1,5;" + cmd_flight + "1,1," + str(Fault_keep_time)
                js = {"CaseID": default_id, "Subsystem": subsys_name, "FaultType": fault_name, "ControlSequence": cmd, "InterestedLog": {}, "TestStatus": "UnFinished", "UniqueIndex": caseid}
                case.append(js) 
        return case
    elif fault_para_num == 3:
        for k in range(step + 1):
            para1 = para_min + step_length * k
            for j in range(step + 1):
                para2 = para_min + step_length * j
                for i in range(step + 1):
                    caseid = caseID_generator(bat, flight_mode, faulttype, default_id)
                    default_id += 1
                    para3 = para_min + step_length * i
                    para = [round(para1, 4), round(para2, 4), round(para3, 4)]
                    cmd_flight = cmd_from_flight_fault(flight_mode, faulttype, fault_para_num, para)
                    cmd = "2,1,0.5,1,15;1,1,5;" + cmd_flight + "1,1," + str(Fault_keep_time)
                    js = {"CaseID": default_id, "Subsystem": subsys_name, "FaultType": fault_name, "ControlSequence": cmd, "InterestedLog": {}, "TestStatus": "UnFinished", "UniqueIndex": caseid}
                    case.append(js)
        return case
    else:  # 默认为para_num = 4的情况
        for m in range(step + 1):
            para1 = para_min + step_length * m
            for k in range(step + 1):
                para2 = para_min + step_length * k
                for j in range(step + 1):
                    para3 = para_min + step_length * j
                    for i in range(step + 1):
                        caseid = caseID_generator(bat, flight_mode, faulttype, default_id)
                        default_id += 1
                        para4 = para_min + step_length * i
                        para = [round(para1, 4), round(para2, 4), round(para3, 4), round(para4, 4)]
                        cmd_flight = cmd_from_flight_fault(flight_mode, faulttype, fault_para_num, para)
                        cmd = "2,1,0.5,1,15;1,1,5;" + cmd_flight + "1,1," + str(Fault_keep_time)
                        js = {"CaseID": default_id, "Subsystem": subsys_name, "FaultType": fault_name, "ControlSequence": cmd, "InterestedLog": {}, "TestStatus": "UnFinished", "UniqueIndex": caseid}
                        case.append(js)
        return case

def cmd_from_flight_fault(flight_mode, faulttype, para_num, para):
    if flight_mode == 0:  # hovering
        cmd = ''
    elif flight_mode == 1:  # waypoints
        cmd = '2,4,1.6,0,0;1,1,5;2,9,3.0,50,0,15,0,3.0,50,-30,15,-90,3.0,10,-30,15,180,3.0,10,0,15,90;1,1,30;'
    elif flight_mode == 2:  # velocity control
        cmd = '2,4,5,0,0;1,1,5;'  # need to change each time !
    elif flight_mode == 3:  # circling
        cmd = '2,4,4,0,0;1,1,10;2,11,15,3,0,40,-15,15;1,1,25;'
    elif flight_mode == 4:  # acceleration
        cmd = '2,10,0.8,10,0;1,1,5;'
    elif flight_mode == 5:  # deceleration
        cmd = '2,4,10,0,0;1,1,5;2,10,0.5,10,1;1,1,2;'
    fault_cmd = cmd_from_fault(faulttype, para_num, para)
    cmd = cmd + fault_cmd
    return cmd


def cmd_from_flight_fault2(flight_mode, faulttype, para_num, para):
    """
    需要考虑：
    1、不同的飞行模式下,故障注入前后的飞行状态
    2、故障注入后,是否需要恢复正常状态继续飞行
    3、还需要考虑故障注入的时刻需要有一个随机量!!!!!
    """
    if flight_mode == 0:  # 对应悬停的状态
        cmd = "2,3,0,0,-25;1,1," + str(round(np.random.uniform(12, 20), 4)) + ";"
        fault_cmd = cmd_from_fault(faulttype, para_num, para)
        cmd = cmd + fault_cmd
    elif flight_mode == 1 and MODE_flight == 0:  # 定点飞行的状态(考虑故障注入后恢复正常的情况)
        cmd = "2,3,0,0,-25;1,1," + str(round(np.random.uniform(10, 15), 4)) + ";2,3," + str(np.random.randint(-40, 40)) + "," + str(np.random.randint(-40, 40)) + "," + str(np.random.randint(-60, -15)) + ";1,1," + str(round(np.random.uniform(4, 8), 4)) + ";"
        fault_cmd = cmd_from_fault(faulttype, para_num, para, mode=1)
        cmd = cmd + fault_cmd + "1,1," + str(round(np.random.uniform(5, 15), 4)) + ";"
        fault_cmd = cmd_from_fault(faulttype, para_num, np.ones(para_num, dtype=int), mode=2)  # 认为1是正常状态，暂时这么写，以后需要修改
        cmd = cmd + fault_cmd
    elif flight_mode == 2:  # 定速飞行的状态
        cmd = "2,3,0,0,-25;1,1," + str(round(np.random.uniform(10, 15), 4)) + ";2,4," + str(round(np.random.uniform(-6, 6), 1)) + "," + str(round(np.random.uniform(-6, 6), 1)) + "," + str(round(np.random.uniform(-6, 0), 1)) + ";1,1," + str(round(np.random.uniform(8, 13), 4)) + ";"
        fault_cmd = cmd_from_fault(faulttype, para_num, para)
        cmd = cmd + fault_cmd 
    elif flight_mode == 1 and MODE_flight == 1:  # 定点飞行的状态(不考虑故障注入后恢复正常的情况)
        cmd = "2,3,0,0,-25;1,1," + str(round(np.random.uniform(10, 15), 4)) + ";2,3," + str(np.random.randint(-170, 170)) + "," + str(np.random.randint(-170, 170)) + "," + str(np.random.randint(-80, -15)) + ";1,1," + str(round(np.random.uniform(4, 8), 4)) + ";"
        fault_cmd = cmd_from_fault(faulttype, para_num, para)
        cmd = cmd + fault_cmd
    return cmd


def cmd_from_fault(faulttype, para_num, para, mode=1):
    if FaultMode == 0:  # Remeber to select, if there is no Fault mode
        fault_cmd = "2,6," + str(faulttype) + ","
    else:
        fault_cmd = "2,6," + str(faulttype) + "," + str(FaultMode) + ','

    if FaultMode == 2:
        # now is only for motor continues fault
        fault_cmd = fault_cmd + '1,' + str(para[0]) + ',' + str(Continues_fault_time[0]) + ',' + '1,' + str(para[1]) + ',' + str(Continues_fault_time[1]) + ',' + '1,' + str(para[2]) + ',' + str(Continues_fault_time[2]) + ',' + '1,' + str(para[3]) + ',' + str(Continues_fault_time[3]) + ';'
    elif FaultMode == 3:
        # For sensor noise fault
        fault_cmd = fault_cmd + str(Sensor_bias[0]) + ',' + str(para[0]) + ',' + str(Sensor_bias[1]) + ',' + str(para[1]) + ',' + str(Sensor_bias[2]) + ',' + str(para[2]) + ';'
    elif FaultMode == 11:
        # For motor cyclicity fault
        fault_cmd = fault_cmd + str(C_Time) + ',' + str(Time_Effect) + ',' + str(para[0]) + "," + str(para[1]) + "," + str(para[2]) + "," + str(para[3]) + ";"
    else:
        if para_num == 1 and mode == 1:
            fault_cmd = fault_cmd + str(para) + ";"
        elif para_num == 1 and mode == 2:
            fault_cmd = fault_cmd + str(para[0]) + ";"
        elif para_num == 2:
            fault_cmd = fault_cmd + str(para[0]) + "," + str(para[1]) + ";"
        elif para_num == 3:
            fault_cmd = fault_cmd + str(para[0]) + "," + str(para[1]) + "," + str(para[2]) + ";"
        elif para_num == 5:
            fault_cmd = fault_cmd + str(para[0]) + "," + str(para[1]) + "," + str(para[2]) + "," + str(para[3]) + "," + str(para[4]) + ";"
        elif para_num == 6:
            fault_cmd = fault_cmd + str(para[0]) + "," + str(para[1]) + "," + str(para[2]) + "," + str(para[3]) + "," + str(para[4]) + ',' + str(para[5]) + ";"
        else:  # 默认为para_num = 4的情况
            fault_cmd = fault_cmd + str(para[0]) + "," + str(para[1]) + "," + str(para[2]) + "," + str(para[3]) + ";"
    return fault_cmd


def testdata_prefer_generator(demand_L, origin_json):
    js = {}
    length = len(demand_L)
    for i in range(length):
        js[demand_L[i]] = []
    origin_json["testdata"] = js
    return origin_json


def subsystem_from_faulttype(faulttype):
    if faulttype >= 123450 and faulttype <= 123451 or faulttype >= 123540 and faulttype <= 123543:
        return "Power subsystem"
    elif faulttype >= 123457 and faulttype <= 123459:
        return "Integrated subsystem"
    elif faulttype >= 123544 and faulttype <= 123548:
        return "Environment subsystem"
    elif faulttype >= 123452 and faulttype <= 123455:
        return "Sensor subsystem"
    elif faulttype == 123456:
        return "GPS subsystem"
    elif faulttype == 123549:
        return "No Fault"
    return "Unknown"


def caseID_generator(bat, flight_mode, faulttype, i):
    std_fault = Faulttype_convert(faulttype)
    if bat == "FaultModelSITL":
        caseID = 1000000000
    elif bat == "FaultModelHITL":
        caseID = 2000000000
    else:  # for real flight, which is not been used yet.
        caseID = 3000000000
    caseID = caseID + flight_mode * 100000000 + std_fault * 1000000 + i
    return caseID


def Faulttype_convert(faulttype):
    std_fault = faulttype - 123450
    if std_fault >= 90:
        std_fault = std_fault - 80
    return std_fault


def testcase_select_func(begin_index, total_index):
    num = total_index - begin_index
    case = str(begin_index)
    for i in range(num):
        case = case + "," + str(begin_index+i+1)
    return case


if __name__ == "__main__":
    if MODE_db == 1:  # 生成全新的测试样例
        basic_json = basic_generator(num="all", path=Path, bat=Runbat, vis_mode="off")
        demand_L = ["*actuator_outputs_0.csv", "*estimator_status_0.csv", "*vehicle_command_0.csv", "*sensor_combined_0.csv", "*vehicle_magnetometer_0.csv", "*estimator_attitude_0.csv", "*vehicle_gps_position_0.csv", "*vehicle_global_position_0.csv"]
        json_with_testdata = testdata_prefer_generator(demand_L, basic_json)
        case_L = fault_case_generator(Faulttype, Flight_mode, fault_para_num, para_min=Para_min, para_max=Para_max, step_length=Step_Length, bat=Runbat)
        length = len(case_L)
        for i in range(length):
            print(case_L[i])
        json_with_testdata["faultcase"].extend(case_L)
        json.dump(json_with_testdata, open("./AutoTestAPI/db_ge.json", 'w'), indent=4)
    elif MODE_db == 2:  # 程序故障后，从指定样例开始，对后续所有样例重新仿真
        testcase_str = testcase_select_func(begin_index=BeginIndex, total_index=TotalIndex)
        path_o = sys.path[0]
        jsonpath = path_o + '/db.json'
        with open(jsonpath, "r", encoding='utf-8') as f:
            db_data = json.load(f)
        db_data["testcase"] = testcase_str
        f.close()
        json.dump(db_data, open("./AutoTestAPI/db.json", 'w'), indent=4)
        
           
