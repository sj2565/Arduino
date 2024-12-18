#pragma once

#include <Wire.h>
#include <BMP085.h>

class MyBarometer
{
public:
	MyBarometer(void)
	{

	}

	~MyBarometer()
	{

	}

private:
	CBMP085 m_barometer;

protected:
	void initBarometer(void)
	{
		Wire.begin();
		m_barometer.Calibration();
	}

public:
	long getPress(void)
	{
		return m_barometer.GetPressure();
	}

	double getTemp(void)
	{
		return m_barometer.GetTemperatureInC();
	}

	double getAlt(void)
	{
		return m_barometer.GetAltitude();
	}

	void setup() {
		// put your setup code here, to run once:
		initBarometer();
	}

	void loop() {
		// put your main code here, to run repeatedly:
		long nPress = getPress();
		pressToSerial(nPress);
	}

	void pressToSerial(long nPress)
	{
		Serial.print(nPress);
	}

	void tempToSerial(double temp)
	{
		Serial.print(temp);
	}

	void altToSerial(double alt)
	{
		Serial.print(alt);
	}
};