/*-------------------------------------------------------------------
StringTok.h: String with Token Operation for Arduino Boards Including Arduino Mega
Copyright (c) 2016-Forever ACE Lab, Korea.
All Rights Reserved. Personal and non-commercial purpose only.
-------------------------------------------------------------------*/

#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

//#define DEF_ARDUINO_MEGA
#define DEF_DBL_PREC            (6)
#define SERIAL_WAIT_TIME_MS (50)

/////////////////////////////////////////////////////////////////////
class StringTok
{
public:
 // Constructor //////////////////////////////////////////////////
 StringTok(void) {
 empty();
 }

 StringTok(char ch) {
 setString(ch);
 }

 StringTok(const char* ptr) {
 setString(ptr);
 }

 StringTok(const String& str) {
 setString(str);
 }

 StringTok(long n) {
 setString(n);
 }

 StringTok(int n) {
 setString(n);
 }

 StringTok(double x, int nPrec = DEF_DBL_PREC) {
 setString(x, nPrec);
 }

 StringTok(float x, int nPrec = DEF_DBL_PREC) {
 setString(x, nPrec);
 }

 StringTok(const StringTok& str) {
 setString(str);  // Copy constructor
 }

 // Basic Methods ////////////////////////////////////////////////
 char getAt(int nPos) const {
 return m_str[nPos];
 }

 char getLastAt(void) const {
 return getAt(getLength() - 1);   // Get the last character.
 }

 size_t getLength(void) const {
 return m_str.length();
 }

 int getPosTok(void) const {
 return m_nPosTok;
 }

 int getPosLine(void) const {
 return m_str.indexOf(EOL);
 }

 String getString(void) const {
 return m_str;
 }

 String getQuote(void) const { // "abc" -> abc
 String sTmp(m_str), sQuote;  sTmp.trim();
 if (sTmp.length() == 0 || sTmp[0] != '"') return sQuote;
 for (int i = 1; i < sTmp.length(); i++) {
 if (sTmp[i] == '"') break;
 else  sQuote += sTmp[i];
 }
 return sQuote;
 }

 String getLine(void) const {
 int nPos = m_str.indexOf(EOL); if (nPos < 0) return "";
 return m_str.substring(0, nPos);
 }

 String getLeft(int nCount) const;
 String getRight(int nCount) const;
 String getMid(int nFirst, int nCount) const;
 StringTok getToken(void);
 StringTok getTokenNum(void);  // Get a token that is a number with or without exponent
 StringTok getTokenWhite(void);  // Get a Token only separated by white characters

 void setString(char ch) {
 m_str = ch;
 initPosTok();
 }

 void setString(const char* ptr) {
 m_str = ptr;
 initPosTok();
 }

 void setString(const String& str) {
 m_str = str;
 initPosTok();
 }

 void setString(long n) {
 m_str = String(n);
 initPosTok();
 }

 void setString(int n) {
 setString((long)n);
 }

 void setString(double x, int nPrec = DEF_DBL_PREC) {
 m_str = String(x, nPrec);
 initPosTok();
 }

 void setString(float x, int nPrec = DEF_DBL_PREC) {
 setString((double)x, nPrec);
 }

 void setString(const StringTok& str) {
 setString(str.getString());
 }

 void setPosTok(int nPos) {
 m_nPosTok = nPos;
 }

 void appendString(char ch) {
 m_str += ch;
 }

 void appendString(const char* ptr) {
 m_str += ptr;
 }

 void appendString(const String& str) {
 m_str += str;
 }

 void appendString(const StringTok& str) {
 appendString(str.getString());
 }

 long atoi(void) const {
 return toLong();
 }

 double atof(void) const {
 return toDouble();
 }

 char charAt(int nPos) const {
 return getAt(nPos);
 }

 char charLastAt(void) const {
 return getLastAt();
 }

 String cutLine(void) {
 int nPos = m_str.indexOf(EOL); if (nPos < 0) return "";
 String sLine = m_str.substring(0, nPos);
 if (nPos + 1 < getLength()) setString(m_str.substring(nPos + 1));
 else empty();
 return sLine;
 }

 StringTok cutToken(void);
 StringTok cutTokenNum(void);
 StringTok cutTokenWhite(void);

 void empty(void) {
 setString("");
 }

 bool hasLine(void) const {
 return m_str.indexOf(EOL) >= 0;
 }

 int indexOf(char c) const {
 return m_str.indexOf(c);
 }

 int indexOf(const String& str) const {
 return m_str.indexOf(str);
 }

 int indexOf(const StringTok& str) const {
 return indexOf(str.getString());
 }

 int indexOf(const char* ptr) const {
 return indexOf(String(ptr));
 }

 void initPosTok(void) {
 setPosTok(0);
 }

 bool isEmpty(void) const {
 return getLength() == 0;
 }

 size_t length(void) const {
 return getLength();
 }

 String toString(void) const {
 return getString();
 }

 int toInt(void) const {
 return (int)m_str.toInt();
 }

 long toLong(void) const {
 return m_str.toInt();
 }

 float toFloat(void) const {
 return m_str.toFloat();
 }

 double toDouble(void) const {
 return m_str.toDouble();
 }

 void trim(void) {
 m_str.trim();
 }

 static bool isDelimit(char ch);
 static bool isWhite(char ch);

 // Unary Operations /////////////////////////////////////////////
 StringTok& operator=(const StringTok& str)
 {
 setString(str);
 return *this;
 }

 StringTok& operator=(const String& str)
 {
 setString(str);
 return *this;
 }

 StringTok& operator=(const char* ptr)
 {
 setString(ptr);
 return *this;
 }

 StringTok& operator=(char ch)
 {
 setString(ch);
 return *this;
 }

 char operator[](int nPos) const {
 return getAt(nPos);
 }

 // Serial Operations /////////////////////////////////////////////
 void appendSerial(void) {
 m_str += getSerialInput();
 }
#ifdef DEF_ARDUINO_MEGA
 void appendSerial1(void) {
 m_str += getSerial1Input();
 }
 void appendSerial2(void) {
 m_str += getSerial2Input();
 }
 void appendSerial3(void) {
 m_str += getSerial3Input();
 }
#endif

 void inputSerial(void) {
 m_str = getSerialInput();
 initPosTok();
 }
#ifdef DEF_ARDUINO_MEGA
 void inputSerial1(void) {
 m_str = getSerial1Input();
 initPosTok();
 }
 void inputSerial2(void) {
 m_str = getSerial2Input();
 initPosTok();
 }
 void inputSerial3(void) {
 m_str = getSerial3Input();
 initPosTok();
 }
#endif

 void clearSerial(void) {
 while (Serial.available() > 0) Serial.read();
 initPosTok();
 }
#ifdef DEF_ARDUINO_MEGA
 void clearSerial1(void) {
 while (Serial1.available() > 0) Serial1.read();
 initPosTok();
 }
 void clearSerial2(void) {
 while (Serial2.available() > 0) Serial2.read();
 initPosTok();
 }
 void clearSerial3(void) {
 while (Serial3.available() > 0) Serial3.read();
 initPosTok();
 }
#endif

 void printSerial(void) {
 Serial.print(m_str);
 }
 void printlnSerial(void) {
 Serial.println(m_str);
 }
#ifdef DEF_ARDUINO_MEGA
 void printSerial1(void) {
 Serial1.print(m_str);
 }
 void printlnSerial1(void) {
 Serial1.println(m_str);
 }
 void printSerial2(void) {
 Serial2.print(m_str);
 }
 void printlnSerial2(void) {
 Serial2.println(m_str);
 }
 void printSerial3(void) {
 Serial3.print(m_str);
 }
 void printlnSerial3(void) {
 Serial3.println(m_str);
 }
#endif

 static String getSerialInput(void) {
 String str;
 while (Serial.available() > 0) str += (char)Serial.read();
 return str;
 }
#ifdef DEF_ARDUINO_MEGA
 static String getSerial1Input(void) {
 String str;
 while (Serial1.available() > 0) str += (char)Serial1.read();
 return str;
 }
 static String getSerial2Input(void) {
 String str;
 while (Serial2.available() > 0) str += (char)Serial2.read();
 return str;
 }
 static String getSerial3Input(void) {
 String str;
 while (Serial3.available() > 0) str += (char)Serial3.read();
 return str;
 }
#endif

 static bool isAvailableSerial(void) {
 return Serial.available() > 0;
 }
#ifdef DEF_ARDUINO_MEGA
 static bool isAvailableSerial1(void) {
 return Serial1.available() > 0;
 }
 static bool isAvailableSerial2void) {
 return Serial2.available() > 0;
 }
 static bool isAvailableSerial3void) {
 return Serial3.available() > 0;
 }
#endif

 // SoftwareSerial Operations /////////////////////////////////////////////
 // SoftwareSerial의 입력을 문자열로 반환
 void appendSerial(SoftwareSerial& swSerial) {
 m_str += getSerialInput(swSerial);
 }
 void inputSerial(SoftwareSerial& swSerial) {
 m_str = getSerialInput(swSerial);
 initPosTok();
 }
 void clearSerial(SoftwareSerial& swSerial) {
 while (swSerial.available() > 0) swSerial.read();
 initPosTok();
 }
 void printSerial(SoftwareSerial& swSerial) {
 swSerial.print(m_str);
 }
 void printlnSerial(SoftwareSerial& swSerial) {
 swSerial.println(m_str);
 }
 static String getSerialInput(SoftwareSerial& swSerial)
 {
 String str;
 while (swSerial.available() > 0) str += (char)swSerial.read();
 return str;
 }
 static bool isAvailableSerial(SoftwareSerial& swSerial) {
 return swSerial.available() > 0;
 }

private:
 // Internal Variables ///////////////////////////////////////////
 static const char EOL = '\n'; // End of line
 String m_str;
 int m_nPosTok; // Token position
};
/////////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------
  Basic Methods
  -------------------------------------------------------------------*/
inline bool StringTok::isDelimit(char ch)
{
 static const char pChar[] = " +-*/<>=()&|!,;:@#$%^\t\r\n[]{}";    // Array for delimeter
 size_t nChar = strlen(pChar);
 for (int i = 0; i < nChar; i++)  if (ch == pChar[i])  return true;
 return false;
}

inline bool StringTok::isWhite(char ch)
{
 static const char pChar[] = " \t\r\n";    // Array for white characters
 size_t nChar = strlen(pChar);
 for (int i = 0; i < nChar; i++)  if (ch == pChar[i])  return true;
 return false;
}

inline StringTok StringTok::getToken(void)
{
 size_t nInput = getLength();
 StringTok str;
 while (isWhite(m_str[m_nPosTok])) {
 m_nPosTok++;
 if (m_nPosTok >= nInput)  return str;
 }
 str.m_str = m_str[m_nPosTok], m_nPosTok++;
 if (isDelimit(str[0]))  return str;

 while (m_nPosTok < nInput)
 {
 if (isDelimit(m_str[m_nPosTok]))  return str;
 str.m_str += m_str[m_nPosTok], m_nPosTok++;
 }
 return str;
}

inline StringTok StringTok::cutToken(void)
{
 StringTok stToken = getToken();
 if (m_nPosTok < getLength()) setString(m_str.substring(m_nPosTok));
 else empty();
 return stToken;
}

inline StringTok StringTok::getTokenWhite(void)
{
 size_t nInput = getLength();
 StringTok str;
 while (isWhite(m_str[m_nPosTok])) {
 m_nPosTok++;
 if (m_nPosTok >= nInput)  return str;
 }
 str.m_str = m_str[m_nPosTok], m_nPosTok++;

 while (m_nPosTok < nInput)
 {
 if (isWhite(m_str[m_nPosTok]))  return str;
 str.m_str += m_str[m_nPosTok], m_nPosTok++;
 }
 return str;
}

inline StringTok StringTok::cutTokenWhite(void)
{
 StringTok stToken = getTokenWhite();
 if (m_nPosTok < getLength()) setString(m_str.substring(m_nPosTok));
 else empty();
 return stToken;
}

inline StringTok StringTok::getTokenNum(void)
{
 StringTok sToken = getToken();
 StringTok sTokenAdd;
 if ((sToken[0] == '-' || sToken[0] == '+') && (m_nPosTok < getLength()) && !isDelimit(getAt(m_nPosTok)))
 {
 sTokenAdd = getToken();
 sToken = sToken.getString() + sTokenAdd.getString();
 }
 if (sToken.getLastAt() == 'e' || sToken.getLastAt() == 'E') // Exponent
 {
 sTokenAdd = getToken();
 sToken = sToken.getString() + sTokenAdd.getString();
 if ((sTokenAdd[0] == '-' || sTokenAdd[0] == '+') && (m_nPosTok < getLength()) && !isDelimit(getAt(m_nPosTok)))
 {
 sTokenAdd = getToken();
 sToken = sToken.getString() + sTokenAdd.getString();
 }
 }
 return sToken;
}

inline StringTok StringTok::cutTokenNum(void)
{
 StringTok stToken = getTokenNum();
 if (m_nPosTok < getLength()) setString(m_str.substring(m_nPosTok));
 else empty();
 return stToken;
}

inline String StringTok::getLeft(int nCount) const
{
 String str;
 for (int i = 0; i < nCount; i++)  str += m_str[i];
 return str;
}

inline String StringTok::getRight(int nCount) const
{
 String str;
 for (int i = getLength() - nCount; i < getLength(); i++)  str += m_str[i];
 return str;
}

inline String StringTok::getMid(int nFirst, int nCount) const
{
 String str;
 for (int i = nFirst; i < nFirst + nCount; i++)  str += m_str[i];
 return str;
}

/*-------------------------------------------------------------------
I/O Methods
-------------------------------------------------------------------*/
inline void scans(String& str)
{
 String sTmp;
 while (1)
 {
 while (Serial.available() > 0) sTmp += (char)Serial.read();
 delay(SERIAL_WAIT_TIME_MS);
 if (Serial.available() <= 0 && sTmp.length() > 0) break; // There are input characters.
 }
 str = sTmp;
}

inline void scans(SoftwareSerial& swSerial, String& str)
{
 String sTmp;
 while (1)
 {
 while (swSerial.available() > 0) sTmp += (char)swSerial.read();
 delay(SERIAL_WAIT_TIME_MS);
 if (swSerial.available() <= 0 && sTmp.length() > 0) break; // There are input characters.
 }
 str = sTmp;
}

inline void scans(StringTok& strTok)
{
 String str; scans(str);
 strTok.setString(str);
}

inline void scans(SoftwareSerial& swSerial, StringTok& strTok)
{
 String str; scans(swSerial, str);
 strTok.setString(str);
}

inline void scans(char& c)
{
 while (Serial.available() <= 0) delay(SERIAL_WAIT_TIME_MS);
 c = (char)Serial.read();
}

inline void scans(SoftwareSerial& swSerial, char& c)
{
 while (swSerial.available() <= 0) delay(SERIAL_WAIT_TIME_MS);
 c = (char)swSerial.read();
}

inline void scans(int& n)
{
 StringTok str; scans(str);
 n = str.toInt();
}

inline void scans(long& n)
{
 StringTok str; scans(str);
 n = str.toLong();
}

inline void scans(SoftwareSerial& swSerial, int& n)
{
 StringTok str; scans(swSerial, str);
 n = str.toInt();
}

inline void scans(SoftwareSerial& swSerial, long& n)
{
 StringTok str; scans(swSerial, str);
 n = str.toLong();
}

inline void scans(float& x)
{
 StringTok str; scans(str);
 x = str.toFloat();
}

inline void scans(double& x)
{
 StringTok str; scans(str);
 x = str.toDouble();
}

inline void scans(SoftwareSerial& swSerial, float& x)
{
 StringTok str; scans(swSerial, str);
 x = str.toFloat();
}

inline void scans(SoftwareSerial& swSerial, double& x)
{
 StringTok str; scans(swSerial, str);
 x = str.toDouble();
}

inline void prints(const String& str)
{
 Serial.print(str);
}

inline void printlns(const String& str)
{
 Serial.println(str);
}

inline void prints(SoftwareSerial& swSerial, const String& str)
{
 swSerial.print(str);
}

inline void printlns(SoftwareSerial& swSerial, const String& str)
{
 swSerial.println(str);
}

inline void prints(const StringTok& str)
{
 Serial.print(str.toString());
}

inline void printlns(const StringTok& str)
{
 Serial.println(str.toString());
}

inline void prints(SoftwareSerial& swSerial, const StringTok& str)
{
 swSerial.print(str.toString());
}

inline void printlns(SoftwareSerial& swSerial, const StringTok& str)
{
 swSerial.println(str.toString());
}

inline void prints(const char* ptr)
{
 String str(ptr); prints(str);
}

inline void printlns(const char* ptr)
{
 String str(ptr); printlns(str);
}

inline void prints(SoftwareSerial& swSerial, const char* ptr)
{
 String str(ptr); prints(swSerial, str);
}

inline void printlns(SoftwareSerial& swSerial, const char* ptr)
{
 String str(ptr); printlns(swSerial, str);
}

inline void prints(char c)
{
 Serial.print(c);
}

inline void printlns(char c)
{
 Serial.println(c);
}

inline void prints(SoftwareSerial& swSerial, char c)
{
 swSerial.print(c);
}

inline void printlns(SoftwareSerial& swSerial, char c)
{
 swSerial.println(c);
}

inline void prints(long n)
{
 Serial.print(n);
}

inline void prints(int n)
{
 prints((long)n);
}

inline void printlns(long n)
{
 Serial.println(n);
}

inline void printlns(int n)
{
 printlns((long)n);
}

inline void prints(SoftwareSerial& swSerial, long n)
{
 swSerial.print(n);
}

inline void prints(SoftwareSerial& swSerial, int n)
{
 prints(swSerial, (long)n);
}

inline void printlns(SoftwareSerial& swSerial, long n)
{
 swSerial.println(n);
}

inline void printlns(SoftwareSerial& swSerial, int n)
{
 printlns(swSerial, (long)n);
}

inline void prints(double x, int nPrec = DEF_DBL_PREC)
{
 Serial.print(x, nPrec);
}

inline void prints(float x, int nPrec = DEF_DBL_PREC)
{
 prints((double)x, nPrec);
}

inline void printlns(double x, int nPrec = DEF_DBL_PREC)
{
 Serial.println(x, nPrec);
}

inline void printlns(float x, int nPrec = DEF_DBL_PREC)
{
 printlns((double)x, nPrec);
}

inline void prints(SoftwareSerial& swSerial, double x, int nPrec = DEF_DBL_PREC)
{
 swSerial.print(x, nPrec);
}

inline void prints(SoftwareSerial& swSerial, float x, int nPrec = DEF_DBL_PREC)
{
 prints(swSerial, (double)x, nPrec);
}

inline void printlns(SoftwareSerial& swSerial, double x, int nPrec = DEF_DBL_PREC)
{
 swSerial.println(x, nPrec);
}

inline void printlns(SoftwareSerial& swSerial, float x, int nPrec = DEF_DBL_PREC)
{
 printlns(swSerial, (double)x, nPrec);
}

inline void printlns(void)
{
 Serial.println("");
}

inline void printlns(SoftwareSerial& swSerial)
{
 swSerial.println("");
}

#undef DEF_ARDUINO_MEGA
#undef DEF_DBL_PREC
#undef SERIAL_WAIT_TIME_MS

/////////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------
Revision Records
---------------------------------------------------------------------
C(2016-12-05)
R(2018-04-01): the line operations were added.
R(2018-09-20): the I/O methods were added.
-------------------------------------------------------------------*/