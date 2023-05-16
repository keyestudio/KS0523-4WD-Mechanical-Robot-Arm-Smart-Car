/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 5.1
 Line Tracking sensor
 http://www.keyestudio.com
*/
#define SensorLeft    6   //input pin of left sensor
#define SensorMiddle  7   //input pin of middle sensor
#define SensorRight   8   //input pin of right sensor
unsigned char SL;        //state of left sensor
unsigned char SM;        //state of middle sensor
unsigned char SR;        //state of right sensor

void setup(){
//set baud rate to 9600
  Serial.begin(9600);
  //set to input mode
  pinMode(SensorLeft,INPUT);
  pinMode(SensorMiddle,INPUT);
  pinMode(SensorRight,INPUT);
}

void loop(){
//read the values of three line tracking sensors
  SL = digitalRead(SensorLeft);
  SM = digitalRead(SensorMiddle);
  SR = digitalRead(SensorRight);
//print the values of three sensors
  Serial.print("SL=");
  Serial.print(SL);
  Serial.print("SM=");
  Serial.print(SM);
  Serial.print("SR=");
  Serial.println(SR);
}
