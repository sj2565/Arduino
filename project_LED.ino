#include <ProjectLed.h>

#define SERIAL_RATE (9600)

ProjectLed projectLed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  projectLed.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  projectLed.loop();
}
