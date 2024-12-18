#pragma once

#define LED_DEF_PORT (13)
#define LED_DEF_BLINK_DELAY (200)

class MyBlink {
public:
	MyBlink() {
		changeLedPort(LED_DEF_PORT);
	}

	MyBlink(int nPort) {
		changeLedPort(nPort);
	}

	MyBlink(int nPort, int nDelay) {
		changeLedPort(nPort);
		changeBlinkDelay(nDelay);
	}

	~MyBlink() {

	}

private:
	int m_nLedPort = LED_DEF_PORT;
	int m_nBlinkDelay = LED_DEF_BLINK_DELAY;

protected:

public:
	void changeLedPort(int nPort) {
		m_nLedPort = nPort;
	}

	void changeBlinkDelay(int nDelay) {
		m_nBlinkDelay = nDelay;
	}

	void blinkLed(long nRepeat) {
		for (int i = 0; i < nRepeat; i++) {
			digitalWrite(m_nLedPort, HIGH);
			delay(m_nBlinkDelay);
			digitalWrite(m_nLedPort, LOW);
			delay(m_nBlinkDelay);
		}
	}

	void setup() {
		pinMode(m_nLedPort, OUTPUT);
		digitalWrite(m_nLedPort, LOW);
	}	
};