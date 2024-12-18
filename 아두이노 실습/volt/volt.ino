#define VOLT_PORT (A0) // 포트번호
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

double getAnalogVolt(){
  int nVolt = analogRead(nVoltPort); // 0~1023, 1023 = 5v
  double volt = map(nVolt, 0, ADC_MAX, 0, ADC_VOLT_MAX * VOLT_PREC)/double VOLT_PREC ; // 0~5
  return volt;  
}

void voltToSerial(double volt){
  Serial.println(volt);
}

void setup() {
  // put your setup code here, to run once:
  initVoltmeter(VOLT_PORT); //초기화 
}

void loop() {
  // put your main code here, to run repeatedly:
  double volt = getAnalogVolt();
  voltToSerial(volt);
  delay(DELAY_MS); 
}
