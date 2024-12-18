#pragma once

class MyScore {
public:
	MyScore() {
		initScore();
	}

	MyScore(long nScore) {
		setScore(nScore);

	}
	~MyScore() {

	}

private:
	long m_nScore = 0;

protected:
	void initScore() {
		m_nScore = 0;
	}

public:
	long getScore(void) {
		return m_nScore;
	}

	void setScore(long nScore) {
		m_nScore = nScore;
	}

	void add(long nVal) {
		m_nScore += nVal;
	}

	void sub(long nVal) {
		m_nScore -= nVal;
	}

	void inc() {
		m_nScore++;
	}

	void dec() {
		m_nScore--;
	}

	void print() {
		Serial.print(m_nScore);
	}

	void println() {
		Serial.println(m_nScore);
	}
};