#include <MyDice.h>
#define SERIAL_RATE (9600)

MyDice myDice;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  myDice.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (myDice.isEmpty()) myDice.setup();
  myDice.loop();
  Serial.println("");
}
