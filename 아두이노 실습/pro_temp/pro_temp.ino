float temperature;  
int reading;  
int lm35Pin = A0;
int ledPin = 13;

void setup()  
{
    analogReference(INTERNAL);
    pinMode (ledPin, OUTPUT) ;
    Serial.begin(115200);
}

void loop()  
{
    reading = analogRead(lm35Pin);
    temperature = reading / 9.31;

    //온도가 30도 위로 올라가면 LED를 켠다
    if(temperature > 30)   {
      digitalWrite (ledPin, HIGH);
    } else {
      digitalWrite (ledPin, LOW);
    }
    Serial.println(temperature);
    delay(1000);   
}
