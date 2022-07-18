/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 7.1
 Bluetooth
 http://www.keyestudio.com
*/
char blue_val;  //used to receive the value of Bluetooth 
void setup() {
  Serial.begin(9600);  //set baud rate to 9600
}

void loop() {
  if(Serial.available() > 0)  //if the Bluetooth signals are received
  {
    blue_val = Serial.read();  //receive
    Serial.println(blue_val);  //Serial port prints Bluetooth value
  }
}
