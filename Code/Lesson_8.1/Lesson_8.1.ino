/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 8.1
 motor driver shield
 http://www.keyestudio.com
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x47);
void setup(){
  pwm.begin();
  pwm.setPWMFreq(60);
}
void loop(){
     pwm.setPWM(0,0,4095);
     pwm.setPWM(1,0,1000);
     pwm.setPWM(2,0,4095);
     pwm.setPWM(3,0,1000);
     pwm.setPWM(4,0,4095);
     pwm.setPWM(5,0,1000);
     pwm.setPWM(6,0,4095);
     pwm.setPWM(7,0,1000);
}
