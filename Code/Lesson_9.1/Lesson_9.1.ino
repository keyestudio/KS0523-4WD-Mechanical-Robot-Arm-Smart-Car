/*
 keyestudio 4wd Robot Arm Smart Car
 lesson 9.1
 Prevent falling Robot
 http://www.keyestudio.com
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x47);
int speeds = 2000; //Initialize speed value
#define SensorLeft    6   //input pin of left sensor
#define SensorMiddle  7   //input pin of middle sensor
#define SensorRight   8   //input pin of right sensor
unsigned char SL;        //state of left sensor
unsigned char SM;        //state of middle sensor
unsigned char SR;        //state of right sensor

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  pwm.begin();
  pwm.setPWMFreq(60);
  //set line tracking sensor to input mode
  pinMode(SensorLeft, INPUT);
  pinMode(SensorMiddle, INPUT);
  pinMode(SensorRight, INPUT);
  stopp();//Car stops
}

void loop() {
  SL = digitalRead(SensorLeft);    //read the values of three line tracking sensor
  SM = digitalRead(SensorMiddle);
  SR = digitalRead(SensorRight);
  if (SM == LOW && SL == LOW && SR == LOW) { //if both are low, go forward
    advance();
  }
  else { //otherwise, go back and turn left
    back();
    delay(500);
    turnL();
    delay(500);
  }
}

void advance()     // going forwards
{
  pwm.setPWM(0, 0, 4095);
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 4095);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 4095);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void turnR()        // turn right
{
  pwm.setPWM(0, 0, 4095);
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 4095);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 0);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
void turnL()      // turn left
{
  pwm.setPWM(0, 0, 0);
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 0);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 4095);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void stopp()         //stop
{
  pwm.setPWM(1, 0, 0);
  pwm.setPWM(3, 0, 0);
  pwm.setPWM(5, 0, 0);
  pwm.setPWM(7, 0, 0);
}
void back()          //back
{
  pwm.setPWM(0, 0, 0);
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 0);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 0);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
