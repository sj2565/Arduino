#include <StringTok.h>
#include <MyNumber.h>
#define SERIAL_RATE (9600)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  String sInput;
  Serial.print("Insert a number: ");
  scans(sInput);
  sInput.trim();
  Serial.println(sInput);
  MyNumber myNum;
  int nHanChar = myNum.getNumHanChar(sInput);
  Serial.println("NUMBER of HANGEUL char = " + String(nHanChar);
  for (int i = 0; i < nHanChar; i++)
  {
    String sChar = myNum.getHanChar(sInput, i);
    Serial.print(sChar);
    Serial.println(myNum.toLong(sChar));
  }
}
