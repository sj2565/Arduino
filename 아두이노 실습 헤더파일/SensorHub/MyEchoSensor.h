#pragma once

#define ECHO_DEF_TRIG_PORT	(2)
#define ECHO_DEF_ECHO_PORT	(3)
#define ECHO_DEF_PRINT_PREC	(3)
#define PULSE_WIDTH_US	(10)
#define PULSE_TIME_UNIT	(1e-6)
#define PULSE_SPEED		(340.)	// in m/s

class MyEchoSensor {
public:
	MyEchoSensor() {
		changePort(ECHO_DEF_TRIG_PORT, ECHO_DEF_ECHO_PORT);
		changePrintPrec(ECHO_DEF_PRINT_PREC);
	}

	MyEchoSensor(int nTrig, int nEcho) {
		changePort(nTrig, nEcho);
		changePrintPrec(ECHO_DEF_PRINT_PREC);
	}

	MyEchoSensor(int nTrig, int nEcho, int nPrec) {
		changePort(nTrig, nEcho);
		changePrintPrec(nPrec);
	}

	~MyEchoSensor() {

	}

private:
	int m_nTrigPort = ECHO_DEF_TRIG_PORT;
	int m_nEchoPort = ECHO_DEF_ECHO_PORT;
	int m_nPrintPrec = ECHO_DEF_PRINT_PREC;

protected:
	void initEchoSensor() {
		pinMode(m_nTrigPort, OUTPUT);
		pinMode(m_nEchoPort, INPUT);
		digitalWrite(m_nTrigPort, LOW);
	}

	double getAnalogRange() {
		trigger();
		unsigned long nTime = readPulse(); // in us
		return nTime * PULSE_TIME_UNIT * PULSE_SPEED; // in m
	}

	void rangeToSerial(double range) { // in m -> in cm
		double rangeCm = range * 100.;	// in cm
		Serial.print(rangeCm, m_nPrintPrec); // in cm
	}

	void trigger() {
		digitalWrite(m_nTrigPort, HIGH);
		delayMicroseconds(PULSE_WIDTH_US);
		digitalWrite(m_nTrigPort, LOW);
	}

	unsigned long readPulse() { // in us
		unsigned long nTime = pulseIn(m_nEchoPort, HIGH);
		return nTime;
	}

public:
	void setup() {
		initEchoSensor();
	}

	void loop() {
		double range = getAnalogRange();
		rangeToSerial(range);
	}

	void changePort(int nTrig, int nEcho) {
		m_nTrigPort = nTrig;
		m_nEchoPort = nEcho;
	}

	void changePrintPrec(int nPrec) {
		m_nPrintPrec = nPrec;
	}
};