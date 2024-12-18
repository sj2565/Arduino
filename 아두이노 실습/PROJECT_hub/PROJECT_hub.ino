#include <ProHub.h>
#define SERIAL_BPS (115200)

ProHub proHub;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  proHub.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  proHub.loop(); 
}
