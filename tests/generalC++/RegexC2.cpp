#include <iostream>
#include "Regex.h"
#include "UnitTests.h"

int testRegex(char*, char*, int*);
void testRegex2(char*, char*);

int main()
{
	std::cout << "Testing Regex\n";
	int mc = 0;
	for (int i = 0; i < 74; i++) {
		int res = testRegex(test[i].pattern, test[i].text, &mc);
		if (res < 0 && test[i].match) {
			std::cout << "Test: " << i + 1 << " failed " << test[i].pattern << " not matched to " << test[i].text << '\n';
		}
		else if (res >= 0 && !test[i].match) {
			std::cout << "Test: " << i + 1 << " failed " << test[i].pattern << " matched to " << test[i].text << '\n';
		}
		else {
			std::cout << "Test: " << i + 1 << " passed, matched " << mc << " chars at position: " << res << '\n';
		}
	}
	char regx[] = "[Tt]he\\s";
	testRegex2(regx, Test2);
	std::cin.get();
	return 0;
}
int testRegex(char* regx, char* text, int* mc) {
	Regex regex(regx);
	int res = regex.match(text);
	*mc = regex.getMatchLength();
	return res;
}
void testRegex2(char* regx, char* text) {
	Regex regex(regx);
	int pos = regex.match(text);
	while (pos > -1) {
		int v = regex.getMatchLength();
		std::cout << "Match found at: " << pos << '\n';
		pos = regex.match(text, pos + v);
	}
}
