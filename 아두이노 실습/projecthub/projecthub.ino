#include <ProjectHub.h>
#define SERIAL_BPS (115200)

ProjectHub projectHub;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  projectHub.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  projectHub.loop();
}
