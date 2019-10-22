This version of the Regular exlpression class is functionaly the same as the more general version except that it makes use of the inbuilt Arduino functions such as isDigit() and isAlphaNumeric() (although in the latter case it should be noted that underscore is not considered alphanumeric so this was added)

The tests folder has Arduino code that runs a sequence of 75 tests from data stored using PROGMEM. This means that the tests will run on an Arduino Uno and similar boards.

The Vector.h file is required as the Regex class uses a vector to store a compiled (tokenised) regular expression. The code in Vector.h is heavily cut back to just the methods required by the Regec class. While additional methods would not have been compiled into the final program this approach meant that there was less code to distract from any review of the project.
