#define VOLT_INPUT_PORT (A0) // 입력받은 포트번호
#define BLINK_OUTPUT (13)   // 출력하는 포트번호
#define VOLT_PREC (1000) // v에 대한 정밀도
#define ADC_MAX (1023) // ADC의 최댓값
#define ADC_VOLT_MAX (5) // 단위 v
#define SERIAL_RATE (9600) // 시리얼에 들어가는 통신속도
#define DELAY_MS (1000) // 단위 ms

int nVoltPort;

void initVoltmeter(int nPort){ 
  nVoltPort = nPort;
  Serial.begin(SERIAL_RATE);
}

void initPort(){
  pinMode(BLINK_OUTPUT, OUTPUT);
}

void blinkLed(int nDelayMs)
{  
  int nHalfDelayMs = nDelayMs/2; 
  digitalWrite(BLINK_OUTPUT, HIGH); // LED on
  delay(nHalfDelayMs); 
  digitalWrite(BLINK_OUTPUT, LOW); // LED off
  delay(nHalfDelayMs); 
}

double getAnalogVolt(){
  int nVolt = analogRead(nVoltPort); // 0~1023, 1023 = 5v
  double volt = map(nVolt, 0, ADC_MAX, 0, ADC_VOLT_MAX * VOLT_PREC)/double VOLT_PREC ; // 0~5
  return volt;  
}

void outputLed(int nInput){
  if (nVoltPort <= 1.)
  blinkLed(1000);
  else if (nVoltPort > 1. && nVoltPort <= 2.)
  blinkLed(2000);
  else if (nVoltPort > 2. && nVoltPort <= 3.)
  blinkLed(3000);
  else if (nVoltPort > 3. && nVoltPort <= 4.)
  blinkLed(4000);
  else if (nVoltPort <= 5.) 
  blinkLed(5000);
}

void voltToSerial(double volt){
  Serial.println(volt);
}

void setup() {
  // put your setup code here, to run once:
  initVoltmeter(VOLT_INPUT_PORT); //초기화
  initPort(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  double volt = getAnalogVolt();
  voltToSerial(volt);
  delay(DELAY_MS);
  int nInput = nVoltPort;
  outputLed(nInput); 
}
