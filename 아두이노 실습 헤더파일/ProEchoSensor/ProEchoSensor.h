#pragma once

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13
#define LED_PIN2 12
#define SERIAL_LATE (115200)
#define TRANSFORM (58.2)

class ProEchoSensor {
public:
	ProEchoSensor(void) {

	}
	~ProEchoSensor() {

	}

    void EchoPin() {
        pinMode(TRIG_PIN, OUTPUT);
        pinMode(ECHO_PIN, INPUT);
        pinMode(LED_PIN, OUTPUT);
        pinMode(LED_PIN2, OUTPUT);
        Serial.begin(SERIAL_LATE);
    }

    void Trig() {
        int distance = 0;

        digitalWrite(TRIG_PIN, HIGH);
        delay(10);
        digitalWrite(TRIG_PIN, LOW);

        distance = pulseIn(ECHO_PIN, HIGH) / TRANSFORM; // micro초 * 초음파 속도 / 2  => 0.0001 * 340(m/s) / 2 를 cm로 변환

        if (distance <= 10) {
            digitalWrite(LED_PIN, HIGH);
            digitalWrite(LED_PIN2, LOW);
        }
        else {
            digitalWrite(LED_PIN, LOW);
            digitalWrite(LED_PIN2, HIGH);
        }
        
        Serial.println(distance); 
    }

    void setup() {
        EchoPin();  
    }

    void loop() {
        Trig();
    }
};