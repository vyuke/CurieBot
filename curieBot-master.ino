//#include <Wire.h>
//#include "LiquidCrystal_I2C.h"
//LiquidCrystal_I2C lcd(0x27, 20, 4);

#include "Servo_Motor.h"//调用小车驱动库文件
#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //申明右轮链接3号口

Servo_Motor sm(Left_wheel, Right_wheel); //创建一个小车对象名为sm

void setup()
{

  pinMode(4, 1);
  pinMode(5, 1);
  pinMode(6, 1);
  pinMode(7, 1);

  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  delay(1000);
  digitalWrite(4, !0);
  digitalWrite(5, !1);
  digitalWrite(7, !0);
  digitalWrite(6, !1);
  delay(1000);

  sm.calibrate();

  sm.turnLeft(45);
  tone(13, 3000);
  delay(50);
  noTone(13);

  sm.turnLeft(45);
  tone(13, 3000);
  delay(50);
  noTone(13);

  sm.turnLeft(45);
  tone(13, 3000);
  delay(50);
  noTone(13);

  sm.turnRight(135);
  tone(13, 3000);
  delay(50);
  noTone(13);
  // sm.run(-100);
  // delay(500);
  // sm.run(100);
  //  delay(1500);

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
