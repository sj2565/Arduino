#pragma once

#define VOLT_DEF_PORT (A0)
#define VOLT_DEF_PRINT_PREC	(3)
#define VOLT_PREC (1000)
#define ADC_MAX (1023)
#define ADC_VOLT_MAX  (5) // in V

class MyVoltmeter {
public:
	MyVoltmeter() {
		changePort(VOLT_DEF_PORT);
		changePrintPrec(VOLT_DEF_PRINT_PREC);
	}

	MyVoltmeter(int nPort) {
		changePort(nPort);
		changePrintPrec(VOLT_DEF_PRINT_PREC);
	}

	MyVoltmeter(int nPort, int nPrec) {
		changePort(nPort);
		changePrintPrec(nPrec);
	}

	~MyVoltmeter() {

	}

private:
	int nVoltPort = VOLT_DEF_PORT;
	int nPrintPrec = VOLT_DEF_PRINT_PREC;

protected:
	void initVoltmeter() {

	}

	void initVoltmeter(int nPort) { // voltmeter is initialized.
		changePort(nPort);
		initVoltmeter();
	}

	void voltToSerial(double volt) {
		Serial.print(volt, nPrintPrec);
	}

public:
	double getAnalogVolt() {
		int nVolt = analogRead(nVoltPort); // 0~1023
		double volt = map(nVolt, 0, ADC_MAX, 0, ADC_VOLT_MAX * VOLT_PREC) / (double)VOLT_PREC; // 0~5 V
		return volt;
	}

	void setup() {
		// put your setup code here, to run once:
		initVoltmeter();
	}

	void loop() {
		// put your main code here, to run repeatedly:
		double volt = getAnalogVolt();
		voltToSerial(volt);
	}

	void changePort(int nPort) {
		nVoltPort = nPort;
	}

	void changePrintPrec(int nPrec) {
		nPrintPrec = nPrec;
	}
};