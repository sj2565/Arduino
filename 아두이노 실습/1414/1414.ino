#include <MyButton.h>
#include <Servo.h>

MyButton myButton(8);
Servo servo;
boolean bServoAng0 = false;

void setup() {
  // put your setup code here, to run once:
  myButton.setup();
  servo.attach(9);
  servo.write(180);
  delay(500);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (myButton.isPosEdge()) {
    if (bServoAng0) servo.write(180);
    else servo.write(0); 
    bServoAng0 = !bServoAng0;
    delay(1000);
  Serial.println("pos edge");
  }
}
