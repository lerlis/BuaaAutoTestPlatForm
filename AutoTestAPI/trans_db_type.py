# Copyright (C) rflylab from School of Automation Science and Electrical Engineering, Beihang University.
# All Rights Reserved.
import json
import numpy as np
import sys

# mode = 1: trans SIL to HIL
# mode = 2: trans HIL to SIL
MODE = 1

def dbJsonReader(jsonpath):
    with open(jsonpath, "r", encoding='utf-8') as f:
        db_data = json.load(f)
    f.close()
    return db_data

if __name__=="__main__":
    path_o = sys.path[0]
    jsonpath = path_o + '/db_ge.json'
    db_data = dbJsonReader(jsonpath)
    case_list = db_data["faultcase"]
    for i in range(len(case_list)):
        case_op = case_list[i]
        unique_index = case_op['UniqueIndex']
        # print(unique_index)
        remain_index = unique_index % 1000000000
        # print(remain_index)
        if MODE == 1:  # SIL to HIL
            db_data["faultcase"][i]['UniqueIndex'] = 2000000000 + remain_index
        elif MODE == 2:  # HIL to SIL
            db_data["faultcase"][i]['UniqueIndex'] = 1000000000 + remain_index
    if MODE == 1:
        db_data['testbat'] = "FaultModelHITL"
    elif MODE == 2:
        db_data['testbat'] = "FaultModelSITL"

    json.dump(db_data, open("./AutoTestAPI/db_ge.json", 'w'), indent=4)