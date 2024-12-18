#include <MyLightSensor.h>
#define SERIAL_RATE (9600)
#define DELAY_MS  (1000)

MyLightSensor myLightSensor(A1);

void setup() {
  // put your setup code here, to run once:
  myLightSensor.setup();
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  myLightSensor.loop();
  Serial.println(" ");
  delay(DELAY_MS);
}
