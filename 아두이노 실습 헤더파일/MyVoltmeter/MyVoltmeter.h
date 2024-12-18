#pragma once

#define VOLT_PREC (1000) 
#define VOLT_DEF_PRINT_PREC (3)
#define ADC_MAX (1023)
#define VOLT_DEF_PORT (A0)
#define ADC_VOLT_MAX (5) 

class MyVoltmeter {
public:
    MyVoltmeter() {
        changePort(VOLT_DEF_PORT);
    }

    MyVoltmeter(int nPort) {
        changePort(nPort);
    }

    ~MyVoltmeter() {

    }

private:
    int nVoltPort = VOLT_DEF_PORT;
    int nVoltprintPrec = VOLT_DEF_PRINT_PREC;

protected:
    void initVoltmeter() {
    }

    double getAnalogVolt() {
        int nVolt = analogRead(nVoltPort);
        double volt = map(nVolt, 0, ADC_MAX, 0, ADC_VOLT_MAX * VOLT_PREC) / double VOLT_PREC;
        return volt;
    }

    void voltToSerial(double volt) {
        Serial.print(volt, nVoltprintPrec);
    }

public:
    void changePort(int nPort) {
        nVoltPort = nPort;
    }

    void changeVoltPrintPrec(int nPrec) {
        nVoltprintPrec = nPrec;
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
};