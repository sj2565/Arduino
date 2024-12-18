#pragma once

#include <StringTok.h>
#define SERIAL_WAIT_DELAY (100)
#define LED_PORT_MIN (2)
#define LED_PORT_MAX (13)
#define BLINK_DEF_DELAY (1000)
#define DELAY_RUN (100)
#define DELAY_SLEEP (1000)

class LedCtrl {
public:
	LedCtrl() {

	}

	~LedCtrl() {

	}

private:
	StringTok m_sInput;
	String m_sToken;
	boolean m_bStart = false;
	boolean m_bBlink = false;
	int m_nBlinkPort = 0;
	int m_nBlinkTime = 0;

protected:
	void initLedCtrl() {
		for (int i = LED_PORT_MIN; i <= LED_PORT_MAX; i++)
		{
			pinMode(i, OUTPUT);
			digitalWrite(i, LOW);
		}
		m_bStart = false;
		m_bBlink = false;
		m_nBlinkPort = -1;
		m_nBlinkTime = BLINK_DEF_DELAY;
	}

	void appendSerial() {
		while (Serial.available() > 0) {
			m_sInput.appendSerial();
			delay(SERIAL_WAIT_DELAY);
		}		
	}

	void cutToken() {
		m_sToken = m_sInput.cutToken().toString();
	}

	void turnLed() {
		cutToken();
		int nPort = m_sToken.toInt();
		if (nPort >= LED_PORT_MIN && nPort <= LED_PORT_MAX) {
			cutToken();
			int nOutput;
			if (m_sToken == "On") nOutput = HIGH;
			else if (m_sToken == "Off") nOutput = LOW;
			else return;
			digitalWrite(nPort, nOutput);
		}
	}
	
	void blinkLed() {
		cutToken();
		m_nBlinkPort = m_sToken.toInt();
		if (m_nBlinkPort >= LED_PORT_MIN && m_nBlinkPort <= LED_PORT_MAX) {
			cutToken();
			if (m_sToken == "On") m_bBlink = true;
			else if (m_sToken == "Off") m_bBlink = false;
			else return;
		}
	}

	void blinkTime() {
		cutToken();
		m_nBlinkTime = m_sToken.toInt();
		if (m_nBlinkTime <= 0) m_nBlinkTime = BLINK_DEF_DELAY;
	}

	void sleep() {
		cutToken();
		int nDelay = m_sToken.toInt();
		if (nDelay > 0) delay(nDelay);
	}

	void exeCommand() {
		cutToken();
		if (m_sToken == "start") m_bStart = true;
		else if (m_sToken == "stop") m_bStart = false;
		else if (m_bStart) {
			if (m_sToken == "turn") turnLed();
			else if (m_sToken == "blink") blinkLed();
			else if (m_sToken == "blinktime") blinkTime();
			else if (m_sToken == "sleep") sleep();
		}
		if (m_bStart) delay(DELAY_RUN);
		else delay(DELAY_SLEEP);
	}

	void exeBlinkLed() {
		digitalWrite(m_nBlinkPort, HIGH);
	    delay(m_nBlinkTime / 2);
		digitalWrite(m_nBlinkPort, LOW);
		delay(m_nBlinkTime / 2);
	}

public:
	void setup() {
		initLedCtrl();
	}

	void loop() {
		appendSerial();
		exeCommand();
		if (m_bBlink) exeBlinkLed();
	}
};