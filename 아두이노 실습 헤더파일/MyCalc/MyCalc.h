#pragma once

#include <StringTok.h>

class MyCalc {
public:
	MyCalc() {
		initEqn();
	}

	~MyCalc() {

	}

private:
	StringTok m_sInput;
	String m_sToken;
	double m_ans = 0.;

protected:
	void initEqn() {
		m_sInput = "";
		m_sToken = "";
		m_ans = 0.;

	}

	void inputEqn() {
		Serial.print(">>");
		while (1) {
			scans(m_sInput);
			m_sInput.trim();
			if (!m_sInput.isEmpty()) break;
		}
		Serial.println(m_sInput.toString());
	}

	boolean getToken() {
		m_sToken = m_sInput.getToken().toString();
		return (m_sToken.length() != 0);
	}

	void calcFun() {
		String sFunName = m_sToken;
		if (!getToken()) return;
		if (m_sToken[0] != '(') return;
		if (!getToken()) return;
		double x = m_sToken.toDouble();
		if (!getToken()) return;
		if (m_sToken[0] != ')') return;
		if (sFunName == "sin") m_ans = sin(x);
		else if (sFunName == "cos") m_ans = cos(x);
		else if (sFunName == "tan") m_ans = tan(x);
	}

	void calcNumber() {
		double x = m_sToken.toDouble();
		if (!getToken()) return;
		char c0p = m_sToken[0];
		if (!getToken()) return;
		double y = m_sToken.toDouble();
		switch (c0p) {
		case '+': m_ans = x + y; break;
		case '-': m_ans = x - y; break;
		case '*': m_ans = x * y; break;
		case '/': m_ans = x / y; break;
		}
	}

	void calcEqn() {
		if (!getToken()) { return; }
		if (isAlpha(m_sToken[0])) calcFun();
		else calcNumber();
	}

	void printAns() {
		Serial.print("ans = ");
		Serial.println(m_ans);
	}

public:
	void setup() {
		initEqn();
	}

	void loop() {
		inputEqn();
		calcEqn();
		printAns();
	}
};