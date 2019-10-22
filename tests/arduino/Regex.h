#ifndef Regex_h
#define Regex_h
#include "Vector.h"
#include <Arduino.h>

class Regex
{
  struct RE{
    int8_t cType;
    union {
      char c;
      char* pc;
    };
  };
  void compile(char*);
  void zapClasses();
  int matchPattern(char*, int);
  int matchPatternToken(int, char*);
  bool isAlphaNum(char);
  bool matchRange(char, char*);
  bool isMeta(char);
  bool matchMeta(char, char);
  bool matchType(char, RE);
  bool matchClass(char, char*);
  bool matchNextToken(int, char*);
  int matchAsterisk(int, char*);
  int matchPlus(int, char*);
  int matchQuestionMark(int, char*);
  Vector<RE> repSet;
  int matchLength;
  public:
    Regex(char*);
    ~Regex();
    int match(char* text, int startPos = 0);
    int getMatchLength();
};
#endif
