#include "Servo_Motor.h"//调用小车驱动库文件
#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //声明右轮链接3号口

Servo_Motor sm(Left_wheel, Right_wheel); //创建一个小车对象名为sm

void setup()
{
  sm.calibrate();//校准
  sm.turnLeft(90);//左转90度
  delay(200);
  sm.turnRight(90);//右转90度
  delay(200);
  sm.run(100);//以100的速度前进
  delay(250);
  sm.stop();//停止运动
  delay(200);
  sm.run(-100);//以100的速度倒退
  delay(250);
  sm.stop();//停止运动
}

void loop()
{

}
