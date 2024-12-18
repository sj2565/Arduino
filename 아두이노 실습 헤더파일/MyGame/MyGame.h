#pragma once

#include <StringTok.h>
#include "MyRand.h"
#include "MyScore.h"
#include "MyBlink.h"

enum GameType {
	GAME_LOSE = 0, GAME_WIN, GAME_TIE, GAME_NULL
};

class MyGame : public MyRand {
public:
	MyGame() {

	}

	~MyGame() {

	}

private:
	MyScore m_scoreWin;
	MyBlink m_blink;

protected:
	String getInputUserStr() {
		StringTok sInput;
		while (1) {
			scans(sInput);
			sInput.trim();
			if (!sInput.isEmpty()) break;
		}
		String str = sInput.toString();
		str.toLowerCase();
		return str;
	}

	long getScoreWin() {
		return m_scoreWin.getScore();
	}

	void setScoreWin(int nScore) {
		m_scoreWin.setScore(nScore);
	}

	void initGame() {
		setSeed();
		m_blink.setup();
	}

	void incScoreWin() {
		m_scoreWin.inc();
	}

	void addScoreWin(long nVal) {
		m_scoreWin.add(nVal);
	}

	void subScoreWin(long nVal) {
		m_scoreWin.sub(nVal);
	}

	void printScoreWin() {
		m_scoreWin.print();
	}

	void printlnScoreWin() {
		m_scoreWin.println();
	}

	void blinkLed() {
		m_blink.blinkLed(m_scoreWin.getScore());
	}

	String gameTypeToStr(GameType nGame) {
		if (nGame == GAME_WIN) return "you win!";
		else if (nGame == GAME_TIE) return "you tie.";
		else if (nGame == GAME_LOSE) return "you lose.";
		else return "";
	}

public:

};