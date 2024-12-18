#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13
#define LED_PIN2 12

float temperature;
int reading;
int lm35Pin = A0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  analogReference(INTERNAL);
  Serial.begin(115200);
}

void loop()
{
  int distance = 0;

  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  distance = pulseIn(ECHO_PIN, HIGH) / 58.2; /* 센치미터(cm) */

  reading = analogRead(lm35Pin);
  temperature = reading / 9.31;

  // 온도가 30도 위로 올라가고 거리가 10cm 이하면 LED 켜짐
  if (distance <= 10 && temperature > 30) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, LOW);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, HIGH);
  }

  Serial.print("거리 : ");
  Serial.print(distance);
  Serial.println("cm");
  Serial.print("온도 : ");
  Serial.println(temperature);
  delay(2000);
}
