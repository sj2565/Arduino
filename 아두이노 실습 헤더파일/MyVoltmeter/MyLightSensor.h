#pragma once

#include "MyVoltmeter.h"
#define LIGHT_DEF_PORT (A1)
#define LIGHT_VIN (5.)
#define LIGHT_REST (1000.)

class MyLightSensor : public MyVoltmeter {
public:
	MyLightSensor() {
		changePort(LIGHT_DEF_PORT);
	}

	MyLightSensor(int nPort) {
		changePort(nPort);
	}

	~MyLightSensor() {

	}

protected:
	void initLightSensor() {
		initVoltmeter();
	}

	double getAnalogLdr() {
		double voltLdr = getAnalogVolt();
		double curLdr = (LIGHT_VIN - voltLdr) / LIGHT_REST;
		return voltLdr / curLdr;
	}

	void ldrToSerial(double ldr) {
		voltToSerial(ldr);

	}
public:
	void setup() {
		initLightSensor();
	}

	void loop() {
		double ldr = getAnalogLdr();
		ldrToSerial(ldr);
	}
};