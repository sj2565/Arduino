#include <MyCalc.h>
#define SERIAL_RATE (9600)

MyCalc myCalc;

void setup() {
  // put your setup code here, to run once:
  myCalc.setup();
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  myCalc.loop();
}
