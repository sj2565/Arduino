int datapin = 8;   // 74HC595의 data(DS) 핀을 연결

int latchpin = 9;  // 74HC595의 latch(ST_CP) 핀을 연결

int clockpin = 10;  // 74HC595의 clock(SH_CP) 핀을 연결


// 공통 양극(Common Anode)방식 세그먼트 0~9 까지 숫자 16진수로 표현

byte digits[] = {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1B,0x01,0x09};


void setup()

{

 // shift register 설정 핀을 출력으로 세팅

 pinMode(latchpin, OUTPUT);

 pinMode(clockpin, OUTPUT);

 pinMode(datapin, OUTPUT);

}


void loop()

{

 // 숫자를 0~9까지 반복

 for (int number = 0; number < 10; number++)

 {

   // latch 핀을 데이터가 들어가기 전에 LOW로 바꿈

   digitalWrite(latchpin, LOW);

   

   // shiftOut 함수 사용시 인자 값

   // DS핀넘버, CLock핀넘버, MSBFIRST or LSBFIRST, 옮길자료(byte)

   shiftOut(datapin, clockpin, LSBFIRST, digits[number]);




   // latch 핀을 데이터가 들어간 후에 HIGH로 바꿈

   digitalWrite(latchpin, HIGH);

   delay(500);

 }

}
