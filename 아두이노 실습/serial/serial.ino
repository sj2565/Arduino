String mystr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String str;
  str = "Two roads diverged in a wood, and I took the one less traveled by, and that has made all the difference. The road number is 1234.5678!";
  Serial.println(str);

  for (int i = 0; i < str.length(); i++)
  {
    char c = str[1];
    Serial.print(c); Serial.print(" : ");
    if (isAlpha(c)) Serial.println("alphabet");
    else if (isDigit(c)) Serial.println("number or digit");
    else if (isPunct(c)) Serial.println("Punctuation");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /* char c[300];
  if (Serial.available())
  {
    byte leng = Serial.readBytes(c, 300);
    Serial.print("알파벳의 갯수 : ");
    Serial.println(leng);

    for(int i = 0; i < leng; i++)
    {
      Serial.print(c[i]);
    }
    Serial.println();
  } */
}
