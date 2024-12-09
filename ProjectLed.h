#pragma once

#include <StringTok.h>

#define LED_PORT_MIN (2)
#define LED_PORT_MAX (13)

#define BLINK_DELAY (1000)
#define SERIAL_DELAY (100)
#define DELAY_RUN (100)

class ProjectLed {
public:
	ProjectLed() {

	}

	~ProjectLed() {

	}

private:
	StringTok Input;
	String Token;

	int BlinkPort = 0;
	boolean Start = false;
	boolean Blink = false;
	
protected:

	void initProjectLed() {
		for (int i = LED_PORT_MIN; i <= LED_PORT_MAX; i++)
		{
			pinMode(i, OUTPUT);
			digitalWrite(i, LOW);
		}
	}

	void cutToken() {
		Token = Input.cutToken().toString();
	}

	void appendSerial() {
		while (Serial.available() > 0) {
			Input.appendSerial();
			delay(SERIAL_DELAY);
		}
	}

	void Command() {
		cutToken();
		if (Token == "start") Start = true;
		else if (Token == "stop") Start = false;
		else if (Start) {
			if (Token == "turnLED") turnLed();
			else if (Token == "blinkLED") blinkLed();
		}
		if (Start) delay(DELAY_RUN);
	}

	void turnLed() {
		cutToken();
		int nPort = Token.toInt();
		if (nPort >= LED_PORT_MIN && nPort <= LED_PORT_MAX) {
			cutToken();
			int nOutput;
			if (Token == "on") nOutput = HIGH;
			else if (Token == "off") nOutput = LOW;
			else return;
			digitalWrite(nPort, nOutput);
		}
	}

	void blinkLed() {
		cutToken();
		BlinkPort = Token.toInt();
		if (BlinkPort >= LED_PORT_MIN && BlinkPort <= LED_PORT_MAX) {
			cutToken();
			if (Token == "on") {
				Blink = true;
			}
			else if (Token == "off") {
				Blink = false;
			}
			else return;
		}
	}

	void delayBlinkLed() {
		digitalWrite(BlinkPort, HIGH);
		delay(BLINK_DELAY);
		digitalWrite(BlinkPort, LOW);
		delay(BLINK_DELAY);
	}

public:
	void setup() {
		initProjectLed();
	}

	void loop() {
		appendSerial();
		Command();
		if (Blink) delayBlinkLed();
	}
};