#include <SensorHub.h>
#define SERIAL_BPS (115200)

SensorHub sensorHub;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  sensorHub.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorHub.loop();
}
