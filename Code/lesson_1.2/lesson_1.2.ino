/*
 keyestudio 4WD Robot Arm Smart Car
 lesson 1.2
 delay
 http://www.keyestudio.com
*/
void setup() {  // initialize digital pin 11 as an output.
   pinMode(3, OUTPUT);
}
// the loop function runs over and over again forever
void loop()
 { digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
   delay(100); // wait for 0.1 second
   digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
   delay(100); // wait for 0.1 second
}//****************************************************************
