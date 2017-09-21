/*
  chenlvzhou 2017.5.20
  http://clz.me/
*/
#ifndef Servo_MOTOR_H
#define Servo_MOTOR_H

#include "Arduino.h"
#include <Servo.h>
#include <MadgwickAHRS.h>

#define DEBUG

#define FORWARD true
#define BACKWARD false

#define RUNNING true
#define STOP false

#define OFFSETANGLE1 0    //校准值？补偿？
#define OFFSETANGLE2 10

#define CALNUM 3

class Servo_Motor
{ 
public:
  Servo_Motor(int Lpin,int Rpin);
  void calibrate();
  void stop();
  void run(int speed);
  void motorL(int speed);
  void motorR(int speed);
  void stopL();
  void stopR();
  void setDirectionL(bool direction);
  void setDirectionR(bool direction);
  void backrun(int speed);
  void turnLeft(float angle,int speed);
  void turnLeft(float angle);
  void turnLeft();
  void turnRight(float angle,int speed);
  void turnRight(float angle);
  void turnRight();
  void brake();
  float getHeading();
  bool left_Sensor_index();//左边巡线传感器信号
  bool mid_Sensor_index();//中间巡线传感器信号
  bool right_Sensor_index();//右边巡线传感器信号
  
private:
  Servo servoL;
  Servo servoR;
  Madgwick filter;
  byte _pinL,_pinR;
  bool _directionL,_directionR;
  bool _stateL,_stateR;
  int _speedL,_speedR;
  float convertRawAcceleration(int aRaw);
  float convertRawGyro(int gRaw);
  uint64_t _calibrationTime;
};

#endif
//git test
//111
///222


