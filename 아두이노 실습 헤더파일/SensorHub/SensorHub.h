#pragma once

#include <MyVoltmeter.h>
#include <MyLightSensor.h>
#include <StringTok.h>

#define DELAY_DEF (1000)

class SensorHub
{
public:
	SensorHub(void)
	{

	}

	~SensorHub()
	{

	}

protected:
	void initSensorHub()
	{
		m_voltmeter.setup();
		m_lightSensor.setup();
	}

	void appendSerial(void)
	{
		delay(m_nDelay);
		while (Serial.available() > 0)
		{
			m_sInput.appendSerial();
			delay(m_nDelay);
		}
	}

	void cutToken(void)
	{
		StringTok sToken = m_sInput.cutToken();
		m_sToken = sToken.toString();
		m_sToken.toLowerCase();
		//if (m_sToken.length() != 0)
		//	Serial.println(m_sToken);
	}

	void exeCommand(void)
	{
		cutToken();
		if (m_sToken == "hub") hubCommand();
		else if (m_sToken == "volt") voltCommand();
		else if (m_sToken == "light") lightCommand();
		else if (m_sToken == "getall") getAllSensors();
		else if (m_sToken == "runall") runAllSensors();
		else if (m_sToken == "delay")
		{
			cutToken();
			int nDelay = m_sToken.toInt();
			if (nDelay > 0) changeDelay(nDelay);
		}
	}

	void runAllSensors(void)
	{
		cutToken();
		int nTime = m_sToken.toInt();
		if (nTime <= 0) return;
		while (1)
		{
			getAllSensors();
			delay(nTime);
			appendSerial();
			cutToken();
			if (m_sToken == "exit") break;
		}
	}

	void turnAllSensors(boolean bOn)
	{
		m_bVoltmeter = m_bLightSensor = bOn;
	}

	void getAllSensors(void)
	{
		Serial.print('['); printDelimit();
		if (m_bLightSensor)
			m_lightSensor.loop();
		else Serial.print('0');
			printDelimit();

		if (m_bVoltmeter)
			m_voltmeter.loop();
		else Serial.print('0');
			printDelimit();
		Serial.println(']'); 
	}

	void getSensors(void)
	{
		if (m_bLightSensor)
		{
			m_lightSensor.loop();
			printDelimit();
		}
		if (m_bVoltmeter)
		{
			m_voltmeter.loop();
			printDelimit();
		}
	}

	void changeAllPrec(int nPrec)
	{
		m_voltmeter.changePrintPrec(nPrec);
		m_lightSensor.changePrintPrec(nPrec);
	}

	void hubCommand(void) 
	{
		cutToken();
		if (m_sToken == "on") turnAllSensors(true);
		else if (m_sToken == "off") turnAllSensors(false);
		else if (m_sToken == "get") getSensors();
		else if (m_sToken == "prec")
		{
			cutToken();
			int nPrec = m_sToken.toInt();
			if (nPrec >= 0) changeAllPrec(nPrec);
		}
	}

	void voltCommand(void)
	{
		cutToken();
		if (m_sToken == "on") m_bVoltmeter = true;
		else if (m_sToken == "off") m_bVoltmeter = false;
		else if (m_sToken == "get")
		{
			if (m_bVoltmeter)
			{
				m_voltmeter.loop();
				printDelimit();
			}
		}
		else if (m_sToken == "prec")
		{
			cutToken();
			int nPrec = m_sToken.toInt();
			if (nPrec >= 0) m_voltmeter.changePrintPrec(nPrec);
		}
	}

	void lightCommand(void)
	{
		cutToken();
		if (m_sToken == "on") m_bLightSensor = true;
		else if (m_sToken == "off") m_bLightSensor = false;
		else if (m_sToken == "get")
		{
			if (m_bLightSensor)
			{
				m_lightSensor.loop();
				printDelimit();
			}
		}
		else if (m_sToken == "prec")
		{
			cutToken();
			int nPrec = m_sToken.toInt();
			if (nPrec >= 0) m_lightSensor.changePrintPrec(nPrec);
		}
	}

	void printDelimit(void) 
	{
		Serial.print(" ");
	}

	void changeDelay(int nDelay) 
	{
		m_nDelay = nDelay;
	}

public:
	void setup(void)
	{
		initSensorHub();
	}

	void loop(void)
	{
		appendSerial();
		//if (!m_sInput.isEmpty())
		//	Serial.println(m_sInput.toString());
		exeCommand();
	}

private:
	MyVoltmeter m_voltmeter;
	MyLightSensor m_lightSensor;
	StringTok m_sInput;
	String m_sToken;
	int m_nDelay = DELAY_DEF;
	boolean m_bVoltmeter = true;
	boolean m_bLightSensor = true;
};