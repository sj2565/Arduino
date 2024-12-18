void setup() {
  pinMode(5, OUTPUT);// Set D5 as OUTPUT
}
 
void loop() {
    digitalWrite(5, HIGH);   // atomize
    delay(10000);              // wait for 10 seconds
    digitalWrite(5, LOW);    // atomization stopped
    delay(10000);              // wait for 10 seconds
}

  
