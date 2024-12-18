#include <LedCtrl.h>

#define SERIAL_RATE (9600)

LedCtrl ledCtrl;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  ledCtrl.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  ledCtrl.loop();
}
