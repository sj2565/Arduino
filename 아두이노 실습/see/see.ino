void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HELLO, WORLD.");
  // Serial.end();
  Serial.println("HELLO, WORLD.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char c = (char)Serial.read();
    Serial.write(c);
  }
  delay(100);
}
