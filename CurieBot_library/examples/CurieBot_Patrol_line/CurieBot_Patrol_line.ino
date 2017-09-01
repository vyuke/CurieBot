#include "Servo_Motor.h"//调用小车驱动库文件
#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //声明右轮链接3号口

Servo_Motor sm(Left_wheel, Right_wheel); //创建一个小车对象名为sm

void setup()
{
  
  sm.calibrate();//校准
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(50);
  noTone(13);//关闭蜂鸣器
 
}

void loop()
{
  if (!sm.left_Sensor_index() && sm.mid_Sensor_index() && sm.right_Sensor_index())//左端传感器检测到黑线
  {
    sm.turnLeft(5);//左转5度
  }
  if (!sm.left_Sensor_index() && !sm.mid_Sensor_index() && sm.right_Sensor_index())//左端传感器检测到黑线
  {
    sm.turnLeft(5);//左转5度
  }
  if (sm.left_Sensor_index() && !sm.mid_Sensor_index() && sm.right_Sensor_index())//中间传感器检测到黑线
  {
    sm.run(50);//速度50直行
  }
  if (sm.left_Sensor_index() && sm.mid_Sensor_index() && !sm.right_Sensor_index())//右端传感器检测到黑线
  {
    sm.turnRight(5);//右转5度
  }
  if (sm.left_Sensor_index() && !sm.mid_Sensor_index() && !sm.right_Sensor_index())//右端传感器检测到黑线
  {
    sm.turnRight(5);//右转5度
  }
  if (sm.left_Sensor_index() && sm.mid_Sensor_index() && sm.right_Sensor_index())//未发现黑线
  {
    sm.run(50);//速度50直行
  }
  if (!sm.left_Sensor_index() && !sm.mid_Sensor_index() && !sm.right_Sensor_index())//三路传感器都检测到黑线
  {
    sm.turnLeft(5);//左转5度
  }
  delay(100);
}
