#include "Regex.h"
#include "UnitTests.h"

template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; } 

void setup() {
  Serial.begin(115200);
  Serial << "Free ram before Tests: " << freeRam() << '\n';
  runTests();
  runOtherTest();
  Serial << "Free ram after Tests: " << freeRam() << '\n';
}
void runTests() {
  int mc = 0;
  char regx[30], txt[30];
  for(int i = 0; i < 74; i++) {
    memset(regx, '\0', 30);
    memset(txt, '\0', 30);
    strcpy_P(regx, (char*)pgm_read_word(&(regxs[i])));
    strcpy_P(txt, (char*)pgm_read_word(&(text[i])));
    bool mtch = pgm_read_byte(match + i);
    int res = testRegex(regx, txt, &mc);
    if (res < 0 && mtch) {
      Serial << "Test: " << i + 1 << " failed " << regx << " not matched to " << txt << '\n';
    }
    else if (res >= 0 && !mtch) {
      Serial << "Test: " << i + 1 << " failed " << regx << " matched to " << txt << '\n';
    }
    else {
      if(mtch){
        Serial << "Test: " << i + 1 << " passed, matched " << mc << " chars at position: " << res << '\n';
      } else {
        Serial << "Test: " << i + 1 << " passed, not matched\n";
      }
    }
  }
}
void runOtherTest() {
  char rx[] = "[Tt]he\\s";
  char lngText[55];
  memset(lngText, '\0', 55);
  for(int s = 0; s < strlen_P(Test2); s++) {
    lngText[s] = pgm_read_byte_near(Test2 + s);
  }
  testRegex2(rx, lngText);
}
void loop() {}

int testRegex(char* regx, char* text, int* mc) {
  Regex regex(regx);
  int res = regex.match(text);
  *mc = regex.getMatchLength();
  return res;
}

void testRegex2(char* regx, char* text) {
  Serial.println("In test 2");
  Regex regex(regx);
  int pos = regex.match(text);
  while (pos > -1) {
    int v = regex.getMatchLength();
    Serial << "Match found at: " << pos << '\n';
    pos = regex.match(text, pos + v);
  }
}
int freeRam()
{
  extern int __heap_start, *__brkval;
  int f;
  return (int) &f - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
