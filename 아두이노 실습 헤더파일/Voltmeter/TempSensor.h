#pragma once

#include "Voltmeter.h"
#define LM35PIN (A0)
#define LIGHT_VIN (0.5)

class TempSensor : public Voltmeter {
public:
	TempSensor() {
		changePort(LM35PIN);
	}

	TempSensor(int nPort) {
		changePort(nPort);
	}

	~TempSensor() {

	}

protected:
	void initTempSensor() {
		initVoltmeter();
	}

	double getAnalogTemp() {
		double voltTemp = getAnalogVolt();
		float voltage = voltTemp * 5.0 / 1024.0;
		double Temp = (voltage - 0.5) * -100;
		return Temp;
	}

	void tempToSerial(double temp) {
		voltToSerial(temp);
	}

public:
	void setup() {
		initTempSensor();
	}

	void loop() {
		double temp = getAnalogTemp();
		tempToSerial(temp);
	}
};