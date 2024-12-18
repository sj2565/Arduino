#pragma once

#define ECHO_DEF_TRIG_PORT (2)
#define ECHO_DEF_ECHO_PORT (3)
#define ECHO_DEF_RANGE_PREC (3)
#define PULSE_WIDTH_US (10)
#define PULSE_TIME_UNIT (1e-6)
#define PULSE_SPEED (340.)

class EchoSensor {
public:
	EchoSensor() {
		changePort(ECHO_DEF_TRIG_PORT, ECHO_DEF_ECHO_PORT);
	}

	EchoSensor(int nTrigPort, int nEchoPort) {
		changePort(nTrigPort, nEchoPort);
	}

	~EchoSensor() {

	}

private:
	int m_nTrigPort = ECHO_DEF_TRIG_PORT;
	int m_nEchoPort = ECHO_DEF_ECHO_PORT;
	int m_nRangePrec = ECHO_DEF_RANGE_PREC;

protected:
	void changePort(int nTrigPort, int nEchoPort) {
		m_nTrigPort = nTrigPort;
		m_nEchoPort = nEchoPort;
	}

	void initEchoSensor() {
		pinMode(m_nTrigPort, OUTPUT);
		pinMode(m_nEchoPort, INPUT);
		digitalWrite(m_nTrigPort, LOW);

	}

	void trigger() {
		digitalWrite(m_nTrigPort, HIGH);
		delayMicroseconds(PULSE_WIDTH_US);
		digitalWrite(m_nTrigPort, LOW);
	}

	unsigned long readPulse() {
		unsigned long nTime = pulseIn(m_nEchoPort, HIGH);
		return nTime;
	}

	double getAnalogRange() {
		trigger();
		unsigned long nTime = readPulse();
		return nTime * PULSE_TIME_UNIT * PULSE_SPEED;
	}

	void rangeToSerial(double range) {
		double rangeCm = range * 100.;
		Serial.print(rangeCm, m_nRangePrec);
	}

public:
	void changeRangePrec(int nRangePrec) {
		m_nRangePrec = nRangePrec;
	}

	void setup() {
		initEchoSensor();
	}
	void loop() {
		double range = getAnalogRange();
		rangeToSerial(range);
	}
};