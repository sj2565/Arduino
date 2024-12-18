#pragma once

#define RAND_DEF_SEED_PORT (A0)
#define RAND_DEF_MAX (10)
#define RAND_DEF_MIN (0)
#define RAND_SEED_MUL (1)


class MyRand {
public:
	MyRand() {
		setSeed();				
	}

	MyRand(int nMax) {
		changeRandMax(nMax);
		setSeed();
	}

	MyRand(int nMin, int nMax) {
		changeRandMin(nMin);
		changeRandMax(nMax);
		setSeed();
	}

	~MyRand() {

	}
private:
	int m_nRandSeedPort = RAND_DEF_SEED_PORT;
	int m_nRandMax = RAND_DEF_MAX;
	int m_nRandMin = RAND_DEF_MIN;

protected:

public:
	long getRand() {
		return random(m_nRandMin, m_nRandMax);
	}
	void setSeed() {
		randomSeed((unsigned long)(analogRead(m_nRandSeedPort) * RAND_SEED_MUL));
	}

	void changeRandSeedPort(int nPort) {
		m_nRandSeedPort = nPort;
	}

	void changeRandMax(int nMax) {
		m_nRandMax = nMax;
	}

	void changeRandMin(int nMin) {
		m_nRandMin = nMin;
	}
};