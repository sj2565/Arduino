String mystr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String str;
  str = "HELLO, WORLD";
  str[1] = 'x';
  String str1 = "This is a test!";
  str += str1;
  for (int i = 0; i < str.length(); i++)
  {
    char c = str[1];
    Serial.print(c); Serial.print(" : ");
    if (isAlpha(c)) Serial.println("alphabet");
    else if (isDigit(c)) Serial.println("number or digit");
    else if (isPunct(c)) Serial.println("Punctuation");
    else if (isWhitespace(c)) Serial.println("Whitespace");
  }
  String str2 = "test";
  if (str1 == str2) Serial.println("Same");
  else Serial.println("Different");
  str.toLowerCase();
  Serial.println(str);
  str.toUpperCase();
  Serial.println(str);
  String str3 = "정보통신";
  Serial.println(str3);
  Serial.println(str3.length());
  Serial.println (str2.indexOf("te"));
  Serial.println (str3.indexOf("통신"));
  Serial.println (str3.indexOf("우"));
  String str4 = "123";
  int n = str4.toInt();
  Serial.println(n);
  String str5 = "5.67";
  double x = str5.toDouble();
  Serial.println(x); 
  String str6(314);
  String str7(1.67);
  Serial.println(str6 + " : " + str7); 
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean bRead = false;
  while (Serial.available()) {
    char c = Serial.read();
    mystr += c;
    bRead = true;
  }
  if (bRead) Serial.println(mystr);
  delay(100);
}
