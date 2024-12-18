#pragma once

#include <StringTok.h>
#include "MyRand.h"
#include "MyScore.h"
#include "MyBlink.h"

#define HAND_MAX (3)

enum HandType {
    HAND_SCI = 0, HAND_ROCK, HAND_PAPER, HAND_NULL
};

enum GameType {
	GAME_LOSE = 0, GAME_WIN, GAME_TIE, GAME_NULL
};

class MyHand : public MyRand {
public:
	MyHand() {
		changeRandMax(HAND_MAX);

	}

	~MyHand() {

	}

private:
	MyScore m_scoreWin;
	MyScore m_scoreTie;
	MyBlink m_blink;
	HandType m_nMyHand = HAND_NULL;
	HandType m_nRandHand = HAND_NULL;

protected:
	String getInputUserStr() {
		StringTok sInput;
		scans(sInput);
		sInput.trim();
		String str = sInput.toString();
		str.toLowerCase();
		return str;
	}

	void initHand() {
		setSeed();
		m_blink.setup();
	}

	GameType checkHand() {
		if (m_nMyHand == m_nRandHand) return GAME_TIE;
		else
		{
			if ((m_nMyHand == HAND_SCI && m_nRandHand == HAND_PAPER) || (m_nMyHand == HAND_ROCK && m_nRandHand == HAND_SCI) || (m_nMyHand == HAND_PAPER && m_nRandHand == HAND_ROCK))
				return GAME_WIN;
			else return GAME_LOSE;
		}
		return GAME_NULL;

	}

	void calcScore(GameType nGame) {
		if (nGame == GAME_WIN)	m_scoreWin.inc();
		else if (nGame == GAME_TIE) m_scoreTie.inc();
		Serial.print("Win game: " ); m_scoreWin.println();
		Serial.print("Tie game: " ); m_scoreTie.println();
	}

	void blinkLed(GameType nGame) {
		if (nGame == GAME_WIN) m_blink.blinkLed(m_scoreWin.getScore());
	}

	void inputUser() {
		Serial.print("Select your hand (scissors, rock, paper): ");
		String sHand = getInputUserStr();
		Serial.println(sHand);
		if (sHand[0] == 's') m_nMyHand = HAND_SCI;
		else if (sHand[0] == 'r') m_nMyHand = HAND_ROCK;
		else if (sHand[0] == 'p') m_nMyHand = HAND_PAPER;
		else {
			m_nMyHand = HAND_NULL;
			Serial.println("Wrong input : " + sHand);
		}
	}

	void inputRand() {
		m_nRandHand = (HandType)getRand();
		Serial.println("Arduino's hand : " + handTypeToStr(m_nRandHand));
	}
	
	String handTypeToStr(HandType nHand) {
		if (nHand == HAND_SCI) return "scissors";
		else if (nHand == HAND_ROCK) return "rock";
		else if (nHand == HAND_PAPER) return "paper";
		else return "";
	}

	String gameTypeToStr(GameType nGame) {
		if (nGame == GAME_WIN) return "YOU WIN";
		else if (nGame == GAME_TIE) return "YOU TIE";
		else if (nGame == GAME_LOSE) return "YOU LOSE";
		else return "";
	}

	void showLogo() {
		Serial.println("====================================");
		Serial.println("My Scissors, Rock, and Paper Game");
		Serial.println("====================================");
	}

public:
	void setup() {
		initHand();
		showLogo();
	}

	void loop() {
		inputUser();
		inputRand();
		GameType nGame = checkHand();
		Serial.println(gameTypeToStr(nGame));
		calcScore(nGame);
		blinkLed(nGame);
	}
};