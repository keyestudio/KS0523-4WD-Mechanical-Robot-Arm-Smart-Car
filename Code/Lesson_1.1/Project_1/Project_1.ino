/*
 keyestudio 4wd Robot Arm Smart Car
 lesson 1.1
 Blink
 http://www.keyestudio.com
*/
void setup()
{
  pinMode(3, OUTPUT);// initialize digital pin 3 as an output.
}
void loop() // the loop function runs over and over again forever
{  
  digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000); // wait for a second
  digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
}
