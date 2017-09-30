#include "Servo_Motor.h"//调用小车驱动库文件
#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //声明右轮链接3号口

Servo_Motor sm(Left_wheel, Right_wheel); //创建一个小车对象名为sm

void setup()
{
  //将板载直流电机驱动信号的引脚设置为输出模式
  pinMode(4, 1);
  pinMode(5, 1);
  pinMode(6, 1);
  pinMode(7, 1);
  //电机正转
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  delay(1000);
  //电机反转
  digitalWrite(4, !0);
  digitalWrite(5, !1);
  digitalWrite(7, !0);
  digitalWrite(6, !1);
  delay(1000);
 
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(500);
  noTone(13);

  sm.calibrate();//校准

  sm.turnLeft(45);//左转45度
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(50);
  noTone(13);

  sm.turnLeft(45);//左转45度
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(50);
  noTone(13);

  sm.turnLeft(45);//左转45度
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(50);
  noTone(13);

  sm.turnRight(135);//右转135度
  tone(13, 3000);//板载蜂鸣器发出频率为3000Hz的声音
  delay(50);
  noTone(13);
 
}

void loop()
{
  
}
