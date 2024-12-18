#define Atomizer A0          

void setup() {
  
  Serial.begin(9600);
  pinMode(Atomizer, OUTPUT); 
  
}

void loop() {
  
Serial.println("Atomization !!!!");
digitalWrite(Atomizer,HIGH);
delay(3000);

Serial.println("Atomization OFF");
digitalWrite(Atomizer,LOW);
delay(3000);

}
