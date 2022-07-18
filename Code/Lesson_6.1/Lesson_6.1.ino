/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 6.1
 IRremote
 http://www.keyestudio.com
*/
#include <IRremote.h>
int RECV_PIN =A0; //IR receiver is connected to A0
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);  //set baud rate to 9600
  irrecv.enableIRIn(); // Enable receiver
}

void loop(){
   if(irrecv.decode(&results)){   
     Serial.println(results.value,HEX); //Wrap word in 16 HEX to output and receive code 
     irrecv.resume();  // Receive the next value
    }
    delay(10);
}
