平台版本：
coptersim:v2.5.0-20220730


改动：
1、用例库标准化：控制序列采用了字符串形式的标准化处理
2、故障注入：采用了标准化故障注入方式，根据故障ID触发相应的故障
3、更新dll模型、GenerateModelDLLFile.p以及PX4MavCtrlV4.py（增加getPX4DataMsg接口，修改getTrueDataMsg接口，增加# struct outCopterStruct结构体数据）文件，可以实时提取到模型数据。


更新：
1、新加了一个db.json文件，此文件用于在python中用户自己设定自己想要的用例和自动测试的顺序，此json文件关联到了数据库，会同步更改。你可以根据自己的测试要求配置自己的json
注：json中的用例需按照CaseID的顺序从小到大排，数据库中也一样，如不是这样，请更改。

2、安全评估方法采用了模糊综合评判的方法


