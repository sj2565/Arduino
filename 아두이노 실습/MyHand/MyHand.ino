#include <MyHand.h>
#define SERIAL_RATE (9600)

MyHand myHand;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  myHand.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  myHand.loop();
}
