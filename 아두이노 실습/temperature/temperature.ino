#define LED_PIN 13
#define LED_PIN2 12

float temperature;
int reading;
int lm35Pin = A0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  analogReference(INTERNAL);
  Serial.begin(115200);
}

void loop()
{
  reading = analogRead(lm35Pin);
  temperature = reading / 9.31;

  if (temperature > 30) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH);
  }

  Serial.print("온도 : ");
  Serial.println(temperature);
  delay(2000);
}
