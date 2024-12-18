#pragma once

#include "MyGame.h"

#define DICE_MAX (6)
#define COIN_INIT_COUNT (30)
#define COIN_EQUAR_MUL (2)

enum DiceCompareType {
	DICE_GREATER = 0, DICE_LESS, DICE_EQUAL, DICE_NULL
};

class MyDice : public MyGame {
public:
	MyDice() {
		changeRandMax(DICE_MAX);
	}

	~MyDice() {
	}

private:
	int m_nGameCoin = 0;
	int m_nMyDice = 0;
	int m_nRandDice = 0;
	DiceCompareType m_nDiceCompareType = DICE_NULL;

protected:
	void initDice() {
		initGame();
		setScoreWin(COIN_INIT_COUNT);
	}

	void inputUserDiceCompare() {
		while (1) {
			Serial.print("Select your choice (greater, less, or equal): ");
			String sCompare = getInputUserStr();
			Serial.println(sCompare);
			if (sCompare[0] == 'g') m_nDiceCompareType = DICE_GREATER;
			else if (sCompare[0] == 'l') m_nDiceCompareType = DICE_LESS;
			else if (sCompare[0] == 'e') m_nDiceCompareType = DICE_EQUAL;
			else {
				Serial.println("Wrong input : " + sCompare);
				m_nDiceCompareType = DICE_NULL;
			}
			if (m_nDiceCompareType != DICE_NULL) break;
		}
	}

	void inputUserGameCoin() {
		int nGameCoin;
		boolean bResult = true;
		while (1) {
			Serial.print("Input your game coin: ");
			scans(nGameCoin);
			Serial.println(nGameCoin);
			if (nGameCoin <= 0 || nGameCoin > getScoreWin()) {
				Serial.print("Wrong game coin: "); Serial.println(nGameCoin);
				bResult = false;
			}
			else bResult = true;
			if (bResult) break;
		}
		m_nGameCoin = nGameCoin;
	}

	void inputUser() {
		inputUserDiceCompare();
		inputUserGameCoin();
	}

	GameType checkDice() {
		if ((m_nDiceCompareType == DICE_GREATER) && (m_nMyDice > m_nRandDice)) return GAME_WIN;
		else if ((m_nDiceCompareType == DICE_LESS) && (m_nMyDice < m_nRandDice)) return GAME_WIN;
		else if ((m_nDiceCompareType == DICE_EQUAL) && (m_nMyDice == m_nRandDice)) return GAME_WIN;
		else return GAME_LOSE;
	}
		
	void calcScore(GameType nGame) {
		if (nGame == GAME_WIN) {
			if (m_nDiceCompareType == DICE_EQUAL) addScoreWin(COIN_EQUAR_MUL * m_nGameCoin);
			else addScoreWin(m_nGameCoin);
		}
		else subScoreWin(m_nGameCoin);
	}

	void blinkLed(GameType nGame) {
		if (nGame == GAME_WIN) MyGame::blinkLed();
	}

	void throwDice() {
		m_nMyDice = getRand();
		m_nRandDice = getRand();
		Serial.print("My dice : "); printlnDiceVal(m_nMyDice);
		Serial.print("Arduino's dice  : "); printlnDiceVal(m_nRandDice);
	}

	void printlnDiceVal(int nDice) {
		Serial.println(nDice + 1);
	}

	void showLogo() {
		Serial.println("*******************************");
		Serial.println("My Dice Game");
		Serial.println("*******************************");
	}

public:
	void setup() {
		initDice();
		showLogo();
	}

	void loop() {
		inputUser();
		throwDice();
		GameType nGame = checkDice();
		Serial.println(gameTypeToStr(nGame));
		calcScore(nGame);
		Serial.print("Your rest coins : "); printlnScoreWin();
		blinkLed(nGame);
	}

	boolean isEmpty() {
		return (getScoreWin() <= 0) ? true : false;
	}
};