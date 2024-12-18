#include <MyBlink.h>
#include <MyRand.h>
#include <MyScore.h>

MyRand myRand(5);
MyScore myScore;
MyBlink myBlink;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myRand.setSeed();
  myBlink.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myRand.getRand());
  myScore.inc();
  myScore.println();
  myBlink.blinkLed(myScore.getScore());
  delay(1000);
}
