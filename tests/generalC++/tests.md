
The RegexC2.cpp file has the code to run the battery of 75 tests stored in UnitTests.h

The output should be:

Testing Regex
Test: 1 passed, matched 1 chars at position: 0
Test: 2 passed, matched 3 chars at position: 0
Test: 3 passed, matched 1 chars at position: 0
Test: 4 passed, matched 0 chars at position: -1
Test: 5 passed, matched 1 chars at position: 0
Test: 6 passed, matched 0 chars at position: -1
Test: 7 passed, matched 0 chars at position: -1
Test: 8 passed, matched 0 chars at position: -1
Test: 9 passed, matched 5 chars at position: 0
Test: 10 passed, matched 1 chars at position: 0
Test: 11 passed, matched 0 chars at position: -1
Test: 12 passed, matched 1 chars at position: 0
Test: 13 passed, matched 1 chars at position: 0
Test: 14 passed, matched 0 chars at position: -1
Test: 15 passed, matched 1 chars at position: 0
Test: 16 passed, matched 0 chars at position: -1
Test: 17 passed, matched 0 chars at position: -1
Test: 18 passed, matched 1 chars at position: 0
Test: 19 passed, matched 8 chars at position: 0
Test: 20 passed, matched 3 chars at position: 0
Test: 21 passed, matched 1 chars at position: 1
Test: 22 passed, matched 0 chars at position: -1
Test: 23 passed, matched 5 chars at position: 1
Test: 24 passed, matched 1 chars at position: 2
Test: 25 passed, matched 2 chars at position: 1
Test: 26 passed, matched 8 chars at position: 0
Test: 27 passed, matched 0 chars at position: -1
Test: 28 passed, matched 8 chars at position: 0
Test: 29 passed, matched 0 chars at position: -1
Test: 30 passed, matched 3 chars at position: 0
Test: 31 passed, matched 2 chars at position: 0
Test: 32 passed, matched 3 chars at position: 0
Test: 33 passed, matched 1 chars at position: 3
Test: 34 passed, matched 4 chars at position: 4
Test: 35 passed, matched 3 chars at position: 0
Test: 36 passed, matched 3 chars at position: 0
Test: 37 passed, matched 1 chars at position: 1
Test: 38 passed, matched 1 chars at position: 1
Test: 39 passed, matched 0 chars at position: -1
Test: 40 passed, matched 1 chars at position: 0
Test: 41 passed, matched 2 chars at position: 0
Test: 42 passed, matched 0 chars at position: -1
Test: 43 passed, matched 0 chars at position: -1
Test: 44 passed, matched 0 chars at position: -1
Test: 45 passed, matched 0 chars at position: -1
Test: 46 passed, matched 0 chars at position: -1
Test: 47 passed, matched 0 chars at position: -1
Test: 48 passed, matched 5 chars at position: 0
Test: 49 passed, matched 6 chars at position: 0
Test: 50 passed, matched 6 chars at position: 0
Test: 51 passed, matched 6 chars at position: 0
Test: 52 passed, matched 7 chars at position: 0
Test: 53 passed, matched 7 chars at position: 0
Test: 54 passed, matched 7 chars at position: 0
Test: 55 passed, matched 8 chars at position: 0
Test: 56 passed, matched 13 chars at position: 0
Test: 57 passed, matched 13 chars at position: 0
Test: 58 passed, matched 13 chars at position: 0
Test: 59 passed, matched 12 chars at position: 0
Test: 60 passed, matched 14 chars at position: 0
Test: 61 passed, matched 16 chars at position: 0
Test: 62 passed, matched 0 chars at position: -1
Test: 63 passed, matched 2 chars at position: 0
Test: 64 passed, matched 2 chars at position: 0
Test: 65 passed, matched 2 chars at position: 0
Test: 66 passed, matched 2 chars at position: 0
Test: 67 passed, matched 2 chars at position: 0
Test: 68 passed, matched 2 chars at position: 0
Test: 69 passed, matched 4 chars at position: 4
Test: 70 passed, matched 0 chars at position: -1
Test: 71 passed, matched 0 chars at position: -1
Test: 72 passed, matched 10 chars at position: 0
Test: 73 passed, matched 7 chars at position: 0
Test: 74 passed, matched 8 chars at position: 0
Match found at: 24
Match found at: 41
Match found at: 196
Match found at: 242
Match found at: 295

Where a test is marked as passed but the position is -1 then there should have been no match between the regular expression and the target text.
