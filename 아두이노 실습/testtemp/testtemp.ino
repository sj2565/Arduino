#include <TempSensor.h>
#define SERIAL_RATE (115200)
#define DELAY_MS (1000)

TempSensor tempSensor(A0);

void setup() {
  // put your setup code here, to run once:
  tempSensor.setup();
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempSensor.loop();
  Serial.print("");
  delay(DELAY_MS);
}
