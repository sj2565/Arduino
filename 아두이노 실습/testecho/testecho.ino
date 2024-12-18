#include <EchoSensor.h>
#define SERIAL_RATE (115200)
#define DELAY_MS (1000)

EchoSensor echoSensor;

void setup() {
  // put your setup code here, to run once:
  echoSensor.setup();
  echoSensor.changeRangePrec(6);
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  echoSensor.loop();
  Serial.println(" ");
  delay(DELAY_MS);
}
