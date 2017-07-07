#include "Servo_Motor.h"
#define Left_wheel 2  //声明左轮连接2号口
#define Right_wheel 3  //声明右轮链接3号口

Servo_Motor sm(Left_wheel,Right_wheel);

void setup(){
//  Serial.begin(115200);
//  while(!Serial);
  sm.calibrate();
  delay(3000);
  sm.run(100);
  delay(3000);
  sm.run(-100);
  delay(3000);
  sm.stop();

  delay(3000);
  sm.turnLeft(90);
  delay(3000);
  sm.stop();
  sm.turnRight(90);

  sm.stop();
}

void loop()
{

}
