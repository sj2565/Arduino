#pragma once

#define LED_PIN 13
#define LED_PIN2 12
#define SERIAL_LATE (115200)
#define VALUE (9.31)

class ProTemperature {
public:
    ProTemperature(void)
    {

    }

    ~ProTemperature()
    {

    }

private:
    float temperature;
    int reading;
    int lm35Pin = A0;

public:
    void TempPin() {
        pinMode(LED_PIN, OUTPUT);
        pinMode(LED_PIN2, OUTPUT);
        analogReference(INTERNAL);
        Serial.begin(SERIAL_LATE);
    }

    void TempMeasure() {
        reading = analogRead(lm35Pin);
        temperature = reading / VALUE;  // AVR의 아날로그 입력범위는 1024이고, ADC 참조 전압을 INTERNAL 1.1V를 했기 때문에 나눠준다.
        
        if (temperature > 30) {
            digitalWrite(LED_PIN, HIGH);
            digitalWrite(LED_PIN2, LOW);
        }
        else {
            digitalWrite(LED_PIN, LOW);
            digitalWrite(LED_PIN2, HIGH);
        }

        Serial.println(temperature);
    }

    void setup() {
        TempPin();
    }

    void loop() {
        TempMeasure();
    }
};
