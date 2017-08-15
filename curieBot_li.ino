#include "Servo_Motor.h"//调用小车驱动库文件

#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //声明右轮链接3号口

Servo_Motor sm(Left_wheel, Right_wheel); //创建一个小车对象名为sm

void setup()
{ Serial.begin(9600);
  sm.calibrate();//校准
  sm.turnLeft(90);//左转90度
  delay(200);//等待200毫秒
  sm.turnRight(90);//右转90度
  delay(200);//等待200毫秒
}

void loop()
{
  if ((sm.left_Sensor_index() == 0) && sm.mid_Sensor_index() && sm.right_Sensor_index())//左端传感器检测到黑线
  {
    sm.turnLeft(5);//左转5度
  }
  if (sm.left_Sensor_index() && (sm.mid_Sensor_index() == 0) && sm.right_Sensor_index())//中间传感器检测到黑线
  {
    sm.run(100);//速度100直行
  }
  if (sm.left_Sensor_index() && sm.mid_Sensor_index() && (sm.right_Sensor_index() == 0))//右端传感器检测到黑线
  {
    sm.turnRight(5);//右转5度
  }
  delay(100);
}

