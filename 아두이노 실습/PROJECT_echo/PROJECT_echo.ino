#include <ProEchoSensor.h>
#define DELAY_MS (1000)

ProEchoSensor proEchoSensor;

void setup() {
  // put your setup code here, to run once:
  proEchoSensor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  proEchoSensor.loop();
  delay(DELAY_MS);
}
