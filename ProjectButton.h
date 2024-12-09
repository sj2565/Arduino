#pragma once

#define BUTTON_DELAY (3)

class ProjectButton {
public:
	ProjectButton(int nPort) {
		changePort(nPort);
	}

	~ProjectButton() {

	}

private:
	int Port = 0;
	int PrevButton = HIGH; 

protected:
	void initButton() {
		pinMode(Port, INPUT_PULLUP);
	}

public:
	
	void changePort(int nPort) {
		Port = nPort;
	}

	boolean Pressed() {
		int nInput = digitalRead(Port);
		return nInput == LOW;
	}

	boolean Edge() {
		delay(BUTTON_DELAY);
		int nInput = digitalRead(Port);
		if (nInput != PrevButton) {
			PrevButton = nInput;
			return true;
		}
		else {
			return false;
		}
	}

	boolean NegEdge() {	
		delay(BUTTON_DELAY);
		int nInput = digitalRead(Port);
		if (nInput != PrevButton) {
			PrevButton = nInput;
			if (nInput == LOW) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	boolean PosEdge() {	
		delay(BUTTON_DELAY);
		int nInput = digitalRead(Port);
		if (nInput != PrevButton) {
			PrevButton = nInput;
			if (nInput == HIGH) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	void setup() {
		initButton();
	}
};