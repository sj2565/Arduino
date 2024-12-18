#pragma once

#define VOLT_PREC (1000)
#define ADC_MAX (1023)
#define ADC_VOLT_MAX (5)
#define VOLT_DEF_PORT (A0)

class Voltmeter {
public:
	Voltmeter() {
		changePort(VOLT_DEF_PORT);
	}

	Voltmeter(int nPort) {
		changePort(nPort);
	}

	~Voltmeter() {

	}

private:
	int nVoltPort = VOLT_DEF_PORT;

protected:
	void initVoltmeter() {
		changePort(nVoltPort);
	}

	double getAnalogVolt() {
		int nVolt = analogRead(nVoltPort);
		double volt = map(nVolt, 0, ADC_MAX, 0, ADC_VOLT_MAX * VOLT_PREC) / (double)VOLT_PREC;
		return volt;
	}

	void voltToSerial(double volt) {
		Serial.println(volt);
	}

public:
	void changePort(int nPort) {
		nVoltPort = nPort;
	}

	void setup() {
		initVoltmeter();
	}
	void loop() {
		double volt = getAnalogVolt();
		voltToSerial(volt);
	}
};