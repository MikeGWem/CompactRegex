#pragma once
#define CHARCLASS_MAX 20
#include "Vector.h"
#include <stdint.h>
#include <string.h>


class Regex
{
	struct RE {
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
	bool isDigit(char);
	bool isAlphaNumeric(char);
	bool isWhiteSpace(char);
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


enum Cons : int8_t { BEGIN, END, QUESTIONMARK, ASTERISK, PLUS, DOT, CHAR, CHARCLASS, CHARCLASSNOT, DIGIT, NOTDIGIT, ALPHA, NOTALPHA, WHITESPACE, NOTWHITESPACE };

Regex::Regex(char* regexp) {
	compile(regexp);
}
Regex::~Regex() {
	zapClasses(); // recover heap space used for classes
}
int Regex::match(char* text, int startPos) {
	if (repSet.size()) {
		if (repSet[0].cType == BEGIN) {
			return (matchPattern(text, 1) == 0) ? 0 : -1;
		}
		else {
			int mPos = matchPattern(text + startPos, 0);
			return (mPos > -1) ? mPos + startPos : mPos;
		}
	}
	return -1;
}
int Regex::getMatchLength() {
	return matchLength;
}
//  private methods
int Regex::matchPattern(char* text, int patternPos) {
	int matchStart = 0, matchPos = 0;
	int j = repSet.size() - 1;
	while (text[0] != '\0') {
		char* workPos = text;
		matchLength = 0;
		matchStart = matchPos;
		for (int i = patternPos; i <= j; i++) {
			int charsMatched = matchPatternToken(i, workPos);
			if (charsMatched == -1) { break; }
			workPos += charsMatched;
			matchLength += charsMatched;
			if (i == j) {
				// match found
				return matchStart;
			}
			if (workPos[0] == '\0') {
				// run out of text but what tokens do we still have?
				if ((i - j) > 1) { return -1; }
			}
		}
		matchPos++;
		text++; // restart text search at next character
	}
	matchLength = 0;
	return -1;
}
int Regex::matchPatternToken(int tokenPos, char* text) {
	int mcs = -1;
	int repSetSize = repSet.size();
	if (tokenPos == repSetSize) {
		return -1;
	}
	RE token = repSet[tokenPos];
	if (token.cType == ASTERISK) {
		mcs = matchAsterisk(tokenPos - 1, text);
	}
	else if (token.cType == PLUS) {
		int mCount = matchPlus(tokenPos - 1, text);
		if (mCount > 0) { mcs = mCount; }
	}
	else if (token.cType == QUESTIONMARK) {
		mcs = matchQuestionMark(tokenPos - 1, text);
	}
	else if (token.cType == END) {
		if (text[0] == '\0') {
			mcs = 0;
		}
	}
	else {
		// first look forward one token
		if (tokenPos + 1 < repSetSize) {
			int8_t typ = repSet[tokenPos + 1].cType;
			if (typ == ASTERISK || typ == PLUS || typ == QUESTIONMARK) {
				return 0;
			}
		}
		if (matchType(text[0], token)) {
			mcs = 1;
		}
	}
	return mcs;
}
bool Regex::isDigit(char c) {
	return (c >= '0') && (c <= '9');
}
bool Regex::isAlphaNumeric(char c) {
	return(isDigit(c) || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || c == '_');
}
bool Regex::isWhiteSpace(char c) {
	return (strchr(" \t\n\r\f\v", c) != NULL);
}
bool Regex::matchRange(char c, char* r) {
	if (r[0] != '\0' && r[1] == '-' && r[2] != '\0') {
		return (c >= r[0]) && (c <= r[2]);
	}
	return false;
}
bool Regex::isMeta(char c) {
	return (strchr("dDwWsS+", c) != NULL);
}

bool Regex::matchMeta(char c, char m) {
	switch (m) {
	case 'd':
		return isDigit(c);
	case 'D':
		return !isDigit(c);
	case 's':
		return isWhiteSpace(c);
	case 'S':
		return !isWhiteSpace(c);
	case 'w':
		return isAlphaNumeric(c);
	case 'W':
		return !isAlphaNumeric(c);
	default:
		return c == m;
	}
}
bool Regex::matchType(char c, RE token) {
	switch (token.cType) {
		case DOT:
			return (c != '\n' && c != '\0');
		case DIGIT:
			return isDigit(c);
		case NOTDIGIT:
			return !isDigit(c);
		case ALPHA:
			return isAlphaNumeric(c);
		case NOTALPHA:
			return !isAlphaNumeric(c);
		case WHITESPACE:
			return isWhiteSpace(c);
		case NOTWHITESPACE:
			return !isWhiteSpace(c);
		case CHARCLASS:
			return matchClass(c, token.pc);
		case CHARCLASSNOT:
			return !matchClass(c, token.pc);
		default:
			return c == token.c;
	}
}
bool Regex::matchNextToken(int tokenPos, char* text) {
	if (tokenPos < repSet.size()) {
		return matchType(text[0], repSet[tokenPos]);
	}
	return false;
}
bool Regex::matchClass(char c, char* clDef) {
	// class may contain one or more range or
	// a list of chars to match against that list might include '-'
	bool range = (clDef[1] == '-' && clDef[2] != '\0');
	if (range) {
		while (range) {
			if (matchRange(c, clDef)) { return true; }
			clDef += 3;
			range = (clDef[1] == '-' && clDef[2] != '\0');
		}
		return false;
	}
	while (clDef[0] != '\0') {
		if (clDef[0] == '\\' && clDef[1] != '\0') {
			if (isMeta(clDef[1])) {
				clDef++;
				if (matchMeta(c, clDef[0])) {
					return true;
				}
			}
		}
		else {
			if (c == clDef[0]) { return true; }
		}
		clDef++;
	}
	return false;
}
// match zero or more chars to previous token
// stopped by lookahead match
int Regex::matchAsterisk(int tokenPos, char* text) {
	int retVal = 0;
	if (matchNextToken(tokenPos + 2, text)) {
		return retVal;
	}
	RE token = repSet[tokenPos];
	while (matchType(text[0], token)) {
		retVal++;
		text++;
		if (text[0] == '\0' || (matchNextToken(tokenPos + 2, text))) { break; }
	}
	return retVal;
}
// match one or more char to previous token
// stopped by lookahead match
int Regex::matchPlus(int tokenPos, char* text) {
	int retVal = 0;
	RE token = repSet[tokenPos];
	while (matchType(text[0], token)) {
		retVal++;
		text++;
		if (text[0] == '\0' || (matchNextToken(tokenPos + 2, text))) { break; }
	}
	return retVal;
}
// match zero or one char to previous token
// even this blocked by lookahead match I think
int Regex::matchQuestionMark(int tokenPos, char* text) {
	int retVal = 0;
	if (matchNextToken(tokenPos + 2, text)) {
		return retVal;
	}
	RE token = repSet[tokenPos];
	if (matchType(text[0], token)) { retVal++; }
	return retVal;
}

// compile() tokenises the regular expression
void Regex::compile(char* regexp) {
	int cPos = 0;
	RE tre;
	while (regexp[cPos] != '\0') {
		tre.pc = NULL;
		switch (regexp[cPos]) {
		case '^':
			tre.cType = BEGIN;
			break;
		case '$':
			tre.cType = END;
			break;
		case '.':
			tre.cType = DOT;
			break;
		case '*':
			tre.cType = ASTERISK;
			break;
		case '?':
			tre.cType = QUESTIONMARK;
			break;
		case '+':
			tre.cType = PLUS;
			break;
		case '\\':
			if (regexp[cPos + 1]) {
				cPos++;
				switch (regexp[cPos]) {
				case 'd':
					tre.cType = DIGIT;
					break;
				case 'D':
					tre.cType = NOTDIGIT;
					break;
				case 'w':
					tre.cType = ALPHA;
					break;
				case 'W':
					tre.cType = NOTALPHA;
					break;
				case 's':
					tre.cType = WHITESPACE;
					break;
				case 'S':
					tre.cType = NOTWHITESPACE;
					break;
				default:
					tre.cType = CHAR;
					tre.c = regexp[cPos];
				}
			}
			break;
		case '[':
		{
			if (regexp[cPos + 1] == '^') {
				tre.cType = CHARCLASSNOT;
				cPos++;
			}
			else {
				tre.cType = CHARCLASS;
			}
			char buff[CHARCLASS_MAX];
			int bPos = 0;
			cPos++;
			while (regexp[cPos] != ']' && regexp[cPos] != '\0' && bPos < CHARCLASS_MAX - 1) {
				buff[bPos] = regexp[cPos];
				bPos++;
				cPos++;
			}
			buff[bPos] = '\0';
			tre.pc = (char*)malloc(++bPos);
			memcpy(tre.pc, buff, bPos);
			break;
		}
		default:
			tre.cType = CHAR;
			tre.c = regexp[cPos];
		}
		repSet.push_back(tre);
		cPos++;
	}
}
void Regex::zapClasses() {
	for (int i = 0, j = repSet.size(); i < j; i++) {
		if (repSet[i].cType == CHARCLASS || repSet[i].cType == CHARCLASSNOT) {
			free(repSet[i].pc);
		}
	}
}
