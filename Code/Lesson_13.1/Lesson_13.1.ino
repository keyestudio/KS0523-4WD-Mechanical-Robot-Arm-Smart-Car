/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 13.1
 Bluetooth Remote Control
 http://www.keyestudio.com
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x47);
int speeds = 2000; //set initial rotation speed of motor

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  pwm.begin();
  pwm.setPWMFreq(60);
  stopp();  //Car stops
}

void loop() {
  if (Serial.available() > 0) {
    switch (Serial.read()) {
      case 'F': advance(); Serial.println("advance"); break; //receive‘F’, go forward
      case 'B': back(); Serial.println("back"); break; //receive‘B’, go back

      case 'L': turnL(); Serial.println("turn left"); break;//receive L’，turn left

      case 'R': turnR(); Serial.println("turn right"); break;//receive‘R’，turn right
      case 'S': stopp(); Serial.println("stop"); break;//receive‘S’，stop
      default : break;
    }
  }
}

void advance()     // going forwards
{
  pwm.setPWM(0, 0, 4095); //turn clockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 4095);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 4095);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void turnR()       //turn right
{
  pwm.setPWM(0, 0, 4095); //turn clockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 4095);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 0); //turn anticlockwise
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
void turnL()      //turn left
{
  pwm.setPWM(0, 0, 0); //turn anticlockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 0);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 4095); //turn clockwise
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 4095);
  pwm.setPWM(7, 0, speeds);
}
void stopp()         //stop
{
  pwm.setPWM(1, 0, 0); // adjust speed to 0
  pwm.setPWM(3, 0, 0);
  pwm.setPWM(5, 0, 0);
  pwm.setPWM(7, 0, 0);
}
void back()          //back
{
  pwm.setPWM(0, 0, 0); //turn anticlockwise
  pwm.setPWM(1, 0, speeds);
  pwm.setPWM(2, 0, 0);
  pwm.setPWM(3, 0, speeds);
  pwm.setPWM(4, 0, 0);
  pwm.setPWM(5, 0, speeds);
  pwm.setPWM(6, 0, 0);
  pwm.setPWM(7, 0, speeds);
}
