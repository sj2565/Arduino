#include <StringTok.h>

#define SERIAL_RATE (9600)
#define LED_PORT (13)
#define LED_BLINK_DELAY (200)
#define RAND_SEED_PORT (A0)
#define RAND_SEED_MUL (100)
#define COIN_MAX (2)

enum CoinType{
  COIN_BACK = 0, COIN_FRONT = 1, COIN_NULL 
};

int m_nScore = 0;

void initCoin() {
  m_nScore = 0;
  pinMode(LED_PORT, OUTPUT);
  randomSeed((unsigned long)(analogRead(A0)*RAND_SEED_MUL));
}

CoinType inputUser() {
  StringTok sInput;
  Serial.print("Select your choice (front or back) : ");
  scans(sInput);
  sInput.trim();
  String sCoin = sInput.toString();
  Serial.println (sCoin);
  CoinType nCoin;
  if (sCoin == "front") 
    nCoin = COIN_FRONT;
  else if (sCoin == "back")
    nCoin = COIN_BACK;
  else{
    nCoin = COIN_NULL;
    Serial.println("Wrong input : " + sCoin);
  }
  return nCoin;
}

int getRand() {
  return random(COIN_MAX);
}

CoinType numToCoinType(int num){
  if (num == 0) return COIN_BACK;
  else if (num == 1) return COIN_FRONT;
  else return COIN_NULL;
}

String CoinTypeToStr(CoinType nCoin){
  if (nCoin == COIN_BACK) return "back";
  else if (nCoin == COIN_FRONT) return "front";
  else return "wrong coin type";
  
}

boolean checkCoin(CoinType nMyCoin, CoinType nCoin) {
  return nMyCoin == nCoin;
}

void calcScore(boolean bResult) {
  if (bResult) m_nScore++;
  Serial.println("Your score: "); 
  Serial.println(m_nScore);
}

void blinkLED(boolean bResult) {
  if (bResult) {
    for (int i = 0; i < m_nScore; i++) {
      digitalWrite(LED_PORT, HIGH);
      delay(LED_BLINK_DELAY);
      digitalWrite(LED_PORT, LOW);
      delay(LED_BLINK_DELAY);
    }
  }
}

void CoinGame(){
  CoinType nMyCoin = inputUser();
  if (nMyCoin == COIN_NULL) return;
  // Serial.println(nMyCoin);
  CoinType nCoin = numToCoinType(getRand());
  Serial.println("Coin result : " + CoinTypeToStr(nCoin));
  boolean bResult = checkCoin(nMyCoin, nCoin);
  String sResult;
  if (bResult) 
  sResult = "You won!";
  else 
  sResult = "You lost!";
  Serial.println(sResult);
  calcScore(bResult);
  blinkLED(bResult);
  Serial.println("=======================");
}

void showLogo(){
  Serial.println("************************");
  Serial.println("        COIN GAME");
  Serial.println("************************");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  initCoin();
  showLogo();
}

void loop() {
  // put your main code here, to run repeatedly:
  CoinGame();
}
