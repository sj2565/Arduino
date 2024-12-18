#include <Servo.h>

Servo servo1; 
int servoPin1 = 9;
int motorPin = 5;

int segValue[4][7] = {
  {0,0,0,0,0,0,1}, //0
  {1,0,0,1,1,1,1}, //1
  {0,0,1,0,0,1,0}, //2
  {0,0,0,0,1,1,0}, //3
};
int segPin[8]={4,6,7,8,10,11,12}; //a,b,c,d,e,f,g 핀

int interruptPin1 = 2; //바람 세기 스위치버턴
int step = 0; //바람의세기 단계

void setup() 
{ 
  pinMode(motorPin, OUTPUT); //DC모터
    
  for(int i=0;i<7;i++){ //7-Segment Display핀 모드를 선언과 동시체 초기 0단계 표시
    pinMode(segPin[i], OUTPUT);
    digitalWrite(segPin[i], segValue[0][i]);
  }

pinMode(interruptPin1, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin1), exchange1, FALLING); 

analogWrite(motorPin, 0); //바람세기 = 0
delay(1000);
}

void exchange1() {
  step++;
  if(step==4) step=0;
  for(int j=0;j<7;j++){
     digitalWrite(segPin[j], segValue[step][j]);        
  }
  switch(step){
    case 0:
     analogWrite(motorPin, 0);
     break;
    case 1:
     analogWrite(motorPin, 85);
     break;
    case 2:
     analogWrite(motorPin, 170);
     break;
    case 3:
     analogWrite(motorPin, 255);
     break;
  }
}
