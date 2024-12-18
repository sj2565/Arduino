#pragma once

#define BUTTON_DELAY (2)

class MyButton {
public:
	MyButton(int nPort) {
		changePort(nPort);
	}

	~MyButton() {

	}

private:
	int m_nPort = 0;
	int m_nPrevButton = HIGH;

protected:
	initButton() {
		pinMode(m_nPort, INPUT_PULLUP);
	}

public:
	void setup() {
		initButton();
	}

	void changePort(int nPort) {
		m_nPort = nPort;
	}

	boolean isPressed() {
		int nInput = digitalRead(m_nPort);
		return nInput == LOW;
	}

	boolean isEdge() {
		delay(BUTTON_DELAY);
		int nInput = digitalRead(m_nPort);
		if (nInput != m_nPrevButton) {
			m_nPrevButton = nInput;
			return true;
		}
		else return false;
	}

	boolean isNegEdge() {	// High -> Low
		delay(BUTTON_DELAY);
		int nInput = digitalRead(m_nPort);
		if (nInput != m_nPrevButton) {
			m_nPrevButton = nInput;
			if (nInput == LOW) return true;
			else return false;
		}
		else return false;
	}

	boolean isPosEdge() {	// Low -> High
		delay(BUTTON_DELAY);
		int nInput = digitalRead(m_nPort);
		if (nInput != m_nPrevButton) {
			m_nPrevButton = nInput;
			if (nInput == HIGH) return true;
			else return false;
		}
		else return false;
	}
};