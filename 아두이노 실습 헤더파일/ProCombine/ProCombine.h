#pragma once

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13
#define LED_PIN2 12
#define DELAY_MS 1000
#define DELAY_TRIG 10
#define VALUE (9.31)
#define TRANSFORM (58.2)

class ProCombine {
public:
    ProCombine() {

    }
    ~ProCombine() {

    }

private:
    float temperature;
    int reading;
    int lm35Pin = A0;

public:
    void SumPin() {
        pinMode(TRIG_PIN, OUTPUT);
        pinMode(ECHO_PIN, INPUT);
        pinMode(LED_PIN, OUTPUT);
        pinMode(LED_PIN2, OUTPUT);
        analogReference(INTERNAL);
        Serial.begin(115200);

    }

    void Measure() {
        int distance = 0;

        digitalWrite(TRIG_PIN, HIGH);
        delay(DELAY_TRIG);
        digitalWrite(TRIG_PIN, LOW);

        distance = pulseIn(ECHO_PIN, HIGH) / TRANSFORM; /* 센치미터(cm) */

        reading = analogRead(lm35Pin);
        temperature = reading / VALUE;

        // 온도가 30도 위로 올라가고 거리가 10cm 이하면 LED 켜짐
        if (distance <= 10 && temperature > 30) {
            digitalWrite(LED_PIN, HIGH);
            digitalWrite(LED_PIN2, LOW);
        }
        else {
            digitalWrite(LED_PIN, LOW);
            digitalWrite(LED_PIN2, HIGH);
        }

        Serial.print("Distance : ");
        Serial.print(distance);
        Serial.println("cm");
        Serial.print("Temperature : ");
        Serial.println(temperature);
        delay(DELAY_MS);
    }

    void setup() {
        SumPin();
    }

    void loop()
    {
        Measure();
    }
};
