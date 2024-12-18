#pragma once
#define NUM_HAN_BYTE (3)

class MyNumber
{
public:
	MyNumber(void)
	{

	}

	~MyNumber()
	{

	}
	// 3 bytes == 1음절
	int getNumHanChar(const String& sInput)
	{
		return sInput.length() / NUM_HAN_BYTE;
	}
	// nPos: 0, 1, 2, ... 음절수 -1
	String getHanChar(const String& sInput, int nHanPos)
	{
		return sInput.substring(nHanPos * NUM_HAN_BYTE, (nHanPos + 1) * NUM_HAN_BYTE);
	}
	long toLong(const String& sChar)
	{
		if (sChar == '일') return 1;
		else if (sChar == '이') return 2;
		else if (sChar == '삼') return 3;
		else if (sChar == '십') return 10;
		else if (sChar == '백') return 100;
		else return 0;
		 
	}
	boolean isCarryChar(const String& sChar)
	{
		return false;
	}
};