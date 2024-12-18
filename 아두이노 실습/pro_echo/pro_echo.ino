#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13

void setup() { 
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}
 
void loop() 
{
  int distance = 0;
    
  digitalWrite(TRIG_PIN, HIGH);
  delay(10); 
  digitalWrite(TRIG_PIN, LOW);

  distance = pulseIn(ECHO_PIN, HIGH)/58.2; /* 센치미터(cm) */

   /* 10cm 이내로 접근 시 LED를 켠다 */  
  if (distance <= 10) { 
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);
}
