#include <StringTok.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  StringTok str1('c');
  StringTok str2("test");
  StringTok str3(123);
  StringTok str4(5.67);
  Serial.println(str1.toString());
  str2.printlnSerial();
  str3.printlnSerial();
  str4.printlnSerial();
  Serial.print("Insert a number: ");
  int num;
  scans(num);
  Serial.println(num);
  if (num == 0) Serial.end();
  else if (num == 1) Serial.println("Start!");
}

void loop() {
  // put your main code here, to run repeatedly:
  StringTok sInput;
  if (Serial.available()){
    sInput.inputSerial();
    sInput.printlnSerial();
  }
  else delay(100);
}
