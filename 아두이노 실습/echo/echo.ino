#include <MyEchoSensor.h>
#define SERIAL_RATE (9600)
#define DELAY_MS (1000)

MyEchoSensor myEchoSensor;

void setup() {
  // put your setup code here, to run once:
  myEchoSensor.setup();
  myEchoSensor.changeRangePrec(6);
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  myEchoSensor.loop();
  Serial.println(" ");
  delay(DELAY_MS);
}
