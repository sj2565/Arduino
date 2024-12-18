#include <ProTemperature.h>
#define DELAY_MS (1000)

ProTemperature proTemperature;

void setup() {
  // put your setup code here, to run once:
  proTemperature.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  proTemperature.loop();
  delay(DELAY_MS);
}
