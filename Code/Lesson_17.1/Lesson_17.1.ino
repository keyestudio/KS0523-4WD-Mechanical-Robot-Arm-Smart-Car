/*
 keyestudio 4wdRobot Arm Smart Car
 lesson 17.1
 Memory handling robot
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo1;  //define the servo of claw
Servo myservo2;  //define the servo 2
Servo myservo3;  //define the servo of  base
int k1=80,k2=120,k3=90;  //initialize angle value of servo 3
int M1[20],M2[20],M3[20]; //used to save the read angle value
int i=0,j=0,t=0;  //i is used to save array, j is for saving the maximum value, t is for while loop
void servo1on(){  //claw opens
  myservo1.write(k1);//use Pulse function
  k1-=1;
  delay(5);
  if(k1<20)k1=20;
}
void servo1off(){ //claw closes
  myservo1.write(k1);//use Pulse function
  k1+=1;
  delay(5);
  if(k1>80)k1=80;
}
void servo2up(){
    myservo2.write(k2);//use Pulse function
    k2+=1;
    delay(10);
    if(k2>120)k2=120;
}
void servo2down(){
    myservo2.write(k2);//use Pulse function
    k2-=1;
    delay(10);
    if(k2<10)k2=10;
}
void servo3left(){
    myservo3.write(k3);//use Pulse function
    k3+=1;
    delay(10);
    if(k3>180)k3=180;
}
void servo3right(){
    myservo3.write(k3);//use Pulse function
    k3-=1;
    delay(10);
    if(k3<1)k3=0;
}

void setup(){
  Serial.begin(9600); //set baud rate to 9600
  myservo1.attach(11);
  myservo2.attach(10);
  myservo3.attach(9);
  myservo1.write(k1);
delay(1000);
  myservo2.write(k2);
delay(1000);
  myservo3.write(k3);
delay(1000);
}

void loop(){
  if(Serial.available()>0){ //receive the Bluetooth signals
    switch(Serial.read()){ 
      case 'f':while('f'){          //robot arm lifts up
                   servo2up();          
                   if(Serial.read()=='s')break;
               }break;
      case 'b':while('b'){          //robot arm lowers
                   servo2down();          
                   if(Serial.read()=='s')break;
               }break; 
      case 'l':while('l'){          // robot arm turns left
                   servo3left();          
                   if(Serial.read()=='s')break;
               }break;
      case 'r':while('r'){          //robot arm turns right
                   servo3right();          
                   if(Serial.read()=='s')break;
               }break;  
      case 'Q':while('Q'){          //claw opens
                   servo1on();          
                   if(Serial.read()=='s')break;
               }break;  
      case 'E':while('E'){          //claw closes
                   servo1off();          
                   if(Serial.read()=='s')break;
               }break;
      case 't':{M1[i]=myservo1.read();    //save the angle value of servos in array
                delay(100);
                M2[i]=myservo2.read();
                delay(100);
                M3[i]=myservo3.read();
                delay(100);
                i++;    //i adds 1
                j=i;    // set the value of i to j
                delay(200);
              }break;
      case 'i':{i=0;    //i clears 0
                t=1;    //enter while loop
                k1=myservo1.read(); //read the angle value and set them to k
                k2=myservo2.read();
                k3=myservo3.read();
                while(t){
                  for(int k=0;k<j;k++){   //loop j times
                    if(k1<M1[k]){   //if the current angle value of servo 1 is less than the value of array 1
                      while(k1<M1[k]){  //while loops and make servo rotate the location where the array is saved
                        myservo1.write(k1);   //servo 1executes actions
                        k1++; // K1 adds 1
                        delay(10);  //delay in 10ms, control the rotation speed of servo
                      }
                    }
                    else{   //when angle value of servo 1 is more than the value saved in array 1 
                      while(k1>M1[k]){   //while loops， make servo rotate the location where the value is saved in array
                        myservo1.write(k1); //servo 1 executes motion
                        k1--;   //k1 reduces 1
                        delay(10);  //delay in 10ms，control the rotation speed of servo
                      }
                    }
                    //the same below
                    if(k2<M2[k]){
                      while(k2<M2[k]){
                        myservo2.write(k2);
                        k2++;
                        delay(10);
                      }
                    }
                    else{
                      while(k2>M2[k]){
                        myservo2.write(k2);
                        k2--;
                        delay(10);
                      }
                    }
                    
                    if(k3<M3[k]){
                      while(k3<M3[k]){
                        myservo3.write(k3);
                        k3++;
                        delay(10);
                      }
                    }
                    else{
                      while(k3>M3[k]){
                        myservo3.write(k3);
                        k3--;
                        delay(10);
                      }
                    }
                    
                  }
                  if(Serial.read()=='t'){ //exit while loop
                    t=0;  
                    break;
                  }
                }
               }break;         
      }
  }
}
