#pragma once

#include <ProTemperature.h>
#include <ProEchoSensor.h>
#include <StringTok.h>

#define DELAY_DEF (500)

class ProHub
{
public:
	ProHub(void) {

	}

	~ProHub() {

	}

private:
	ProTemperature proTemperature;
	ProEchoSensor proEchoSensor;
	StringTok m_sInput;
	String m_sToken;
	int m_nDelay = DELAY_DEF;
	boolean m_bTempSensor = true;
	boolean m_bEchoSensor = true;
	
protected:

	void initProjectHub() {
		proTemperature.setup();
		proEchoSensor.setup();
	}

	void appendSerial(void) {
		while (Serial.available() > 0)
		{
			m_sInput.appendSerial();
			delay(m_nDelay);
		}
	}

	void cutToken(void) {
		StringTok sToken = m_sInput.cutToken();
		m_sToken = sToken.toString();
		m_sToken.toLowerCase();
	}

	void printDelimt() {
		Serial.println("");
	}

	void printLine() {
		Serial.println("-------------------------------------------------");
	}

	void changeDelay(int nDelay) {
		m_nDelay = nDelay;
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
			if (m_sToken == "end") break;
		}
	}

	void getAllSensors(void)
	{
		if (m_bTempSensor)
			proTemperature.loop();
		else Serial.print('0');

		if (m_bEchoSensor)
			proEchoSensor.loop();
		else Serial.print('0');
		printDelimt();
		printLine();
	}

	void turnAllSensors(boolean bOn) {
		
		m_bTempSensor = bOn;
		m_bEchoSensor = bOn;
		
	}

	void getSensors(void)
	{
		if (m_bTempSensor && m_bEchoSensor)
		{
			proTemperature.loop();
			proEchoSensor.loop();
			printDelimt();
		}
	}

	void exeCommand(void) {
		cutToken();
		if (m_sToken == "hub") hubCommand();
		else if (m_sToken == "echo") echoCommand();
		else if (m_sToken == "temp") tempCommand();
		else if (m_sToken == "start") runAllSensors();
		else if (m_sToken == "delay")
		{
			cutToken();
			int nDelay = m_sToken.toInt();
			if (nDelay > 0) changeDelay(nDelay);
		}
	}

	void hubCommand() {
		cutToken();
		if (m_sToken == "on") turnAllSensors(true);
		else if (m_sToken == "off") turnAllSensors(false);
		else if (m_sToken == "get") getSensors();
	}

	void tempCommand() {
		cutToken();
		if (m_sToken == "on") m_bTempSensor = true;
		else if (m_sToken == "off") m_bTempSensor = false;
		else if (m_sToken == "get") {
			if (m_bTempSensor) {
				proTemperature.loop();
				printDelimt();
			}
		}
	}

	void echoCommand() {
		cutToken();
		if (m_sToken == "on") m_bEchoSensor = true;
		else if (m_sToken == "off") m_bEchoSensor = false;
		else if (m_sToken == "get") {
			if (m_bEchoSensor) {
				proEchoSensor.loop();
				printDelimt();
			}
		}
	}

public:
	void setup() {
		initProjectHub();
	}

	void loop() {
		appendSerial();
		exeCommand();
	}
};