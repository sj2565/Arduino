#pragma once

#include "MyVoltmeter.h"

#define LIGHT_DEF_PORT	(A1)
#define LIGHT_DEF_PRINT_PREC	(3)
#define LIGHT_VIN	(5.)
#define LIGHT_REST	(1000.)

class MyLightSensor : public MyVoltmeter {
public:
	MyLightSensor() {
		changePort(LIGHT_DEF_PORT);
		changePrintPrec(LIGHT_DEF_PRINT_PREC);
	}

	MyLightSensor(int nPort) {
		changePort(nPort);
		changePrintPrec(LIGHT_DEF_PRINT_PREC);
	}

	MyLightSensor(int nPort, int nPrec) {
		changePort(nPort);
		changePrintPrec(nPrec);
	}

	~MyLightSensor() {

	}

protected:
	void initLightSensor() {
		initVoltmeter();
		// init of light sensor
	}

	void ldrToSerial(double ldr) {
		voltToSerial(ldr);
	}

public:
	double getAnalogLdr() {
		double voltLdr = getAnalogVolt();
		double curLdr = (LIGHT_VIN - voltLdr) / LIGHT_REST;
		return voltLdr / curLdr; // R = V/I
	}

	void setup() {
		initLightSensor();
	}

	void loop() {
		double ldr = getAnalogLdr();
		ldrToSerial(ldr);
	}
};