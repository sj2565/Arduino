#include <ProjectServo.h>

#define SERIAL_RATE (9600)

ProjectServo projectServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  projectServo.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  projectServo.loop();
}
