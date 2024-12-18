#include <Voltmeter.h>
#define SERIAL_RATE (115200)
#define DELAY_MS (1000)

Voltmeter voltmeter(A1);

void setup() {
  // put your setup code here, to run once:
  voltmeter.setup();
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltmeter.loop();
  delay(DELAY_MS);
}
