#define BLINK_INPUT (8) // 8번포트 
#define BLINK_OUTPUT (13) // 13포트
#define BLINK_ON_DELAY (1000) // 깜빡임 1초에 한번
#define BLINK_OFF_DELAY (2000) // 딜레이 2초

void initPort(){ // initPort함수 선언
  pinMode(BLINK_INPUT, INPUT); // 사용자 입력 핀번호 
  pinMode(BLINK_OUTPUT, OUTPUT);  // LED 출력 핀번호 
}

int checkPort(){ // 포트에 입력이 들어왔는지 체크 함수 선언
  return digitalRead(BLINK_INPUT);  
}

void blinkLed(int nDelayMs)
{  
  int nHalfDelayMs = nDelayMs/2; 
  digitalWrite(BLINK_OUTPUT, HIGH); // LED on
  delay(nHalfDelayMs); 
  digitalWrite(BLINK_OUTPUT, LOW); // LED off
  delay(nHalfDelayMs); 
}

void outputLed(int nInput){ 
  if (nInput == HIGH) blinkLed(BLINK_ON_DELAY);
  else blinkLed(BLINK_OFF_DELAY); // LOW
}

// setup과 loop코드를 짧게 하기위해 위에 함수 선언

void setup() {
  // put your setup code here, to run once:
  initPort();
}

void loop() {
  // put your main code here, to run repeatedly:
  int nInput = checkPort(); // Input이 checkPort를 통해 들어옴
  outputLed(nInput); // outputLed는 입력을 받아야 LED깜빡임
}
