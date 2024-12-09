#pragma once

#include <StringTok.h>
#include <Servo.h>

#define SERIAL_DELAY	(500)

Servo servo;

class ProjectServo {

public:
	ProjectServo() {

	}

	~ProjectServo() {

	}

private:
	StringTok Input;
	int servoPin = 9;
	int angle = 0;
	int value = 0;
	int num = 0;
	
protected:
	void Servoangle() {
		for (angle = 0; angle < 180; angle++) {
			servo.write(angle);
			delay(15);
		}
		for (angle = 180; angle > 0; angle--) {
			servo.write(angle);
			delay(15);
		}
	}

	void Servovalue() {
		if (Serial.available()) {
			char in_data;
			in_data = Serial.read();
			if (in_data == '1') {
				value += 30;
				if (value == 180) value = 0;
			}
			else value = 0;

			servo.write(value);
		}
	}

	void appendSerial() {
		while (Serial.available() > 0) {
			Input.appendSerial();
			delay(SERIAL_DELAY);
		}
	}

	void showsentence() {
		Serial.println("Start Servo Motor (Go) : ");
		while (1) {
			scans(Input);
			Input.trim();
			if (!Input.isEmpty()) break;
		}
		Serial.println(Input.toString());
	}
			
public:
	void setup() {
		servo.attach(servoPin);		
		appendSerial();
	}

	void loop() {
		Servoangle();
		Servovalue();
		showsentence();
	}
};