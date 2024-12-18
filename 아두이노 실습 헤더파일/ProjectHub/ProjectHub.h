#pragma once

#include <Voltmeter.h>
#include <TempSensor.h>
#include <EchoSensor.h>
#include <StringTok.h>

#define DELAY_DEF (1000)
#define TRIG_PIN (2)



class ProjectHub
{
public:
	ProjectHub(void) {
		
	}

	~ProjectHub() {

	}
	
protected:
	void initProjectHub() {
		voltmeter.setup();
		tempSensor.setup(); 
		echoSensor.setup();
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
			if (m_sToken == "exit") break;
		}
	}

	void getAllSensors(void)
	{
		Serial.print("Distance : ");
		if (m_bEchoSensor) 
			echoSensor.loop();
		else Serial.print('0');
		printDelimt();

		Serial.print("Temperature : ");
		if (m_bTempSensor)
			tempSensor.loop();
		else Serial.print('0');
		printDelimt();
	}

	void turnAllSensors(boolean bOn) {
		m_bEchoSensor = bOn;
		m_bTempSensor = bOn;
	}

	void getSensors(void)
	{
		if (m_bEchoSensor)
		{
			echoSensor.loop();
			printDelimt();
		}
		if (m_bTempSensor)
		{
			tempSensor.loop();
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

	void echoCommand() {
		cutToken();
		if (m_sToken == "on") m_bEchoSensor = true;
		else if (m_sToken == "off") m_bEchoSensor = false;
		else if (m_sToken == "get") {
			if (m_bEchoSensor) {
				echoSensor.loop();
				printDelimt();
			}
		}	
	}

	void tempCommand() {
		cutToken();
		if (m_sToken == "on") m_bTempSensor = true;
		else if (m_sToken == "off") m_bTempSensor = false;
		else if (m_sToken == "get") {
			if (m_bTempSensor) {
				tempSensor.loop();
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
	
private:
	Voltmeter voltmeter;
	TempSensor tempSensor;
	EchoSensor echoSensor;
	StringTok m_sInput;
	String m_sToken;
	int m_nDelay = DELAY_DEF;
	boolean m_bEchoSensor = true;
	boolean m_bTempSensor = true;
};