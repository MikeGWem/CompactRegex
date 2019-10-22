#pragma once

struct test {
	bool match;
	char pattern[26];
	char text[20];
}
test[] =
{
{ true, "\\d", "5"                },            // 1
{ true,  "\\w+",                      "hej" }, // 2
{ true,  "\\s",                       "\t \n" }, // 3
{ false, "\\S",                       "\t \n" }, // 4
{ true,  "[\\s]",                     "\t \n" }, //5
{ false, "[\\S]",                     "\t \n" }, //6
{ false, "\\D",                       "5" },     // 7
{ false, "\\W+",                      "hej" },   // 8
{ true,  "[0-9]+",                    "12345" }, // 9
{ true,  "\\D",                       "hej" },   // 10
{ false, "\\d",                       "hej" }, // 11
{ true,  "[^\\w]",                    "\\" }, // 12
{ true,  "[\\W]",                     "\\" },  //13
{ false, "[\\w]",                     "\\" },  //14
{ true,  "[^\\d]",                    "d" },  //15
{ false, "[\\d]",                     "d" },  //16
{ false, "[^\\D]",                    "d" },  //17
{ true,  "[\\D]",                     "d" },  // 18
{ true,  "^.*\\\\.*$",                "c:\\Tools" }, // 19
{ true,  "^[\\+-]*[\\d]+$",           "+27" },  // 20
{ true,  "[abc]",                     "1c2" },  // 21
{ false, "[abc]",                     "1C2" }, // 22
{ true,  "[1-5]+",                    "0123456789" }, // 23
{ true,  "[.2]",                      "1C2" }, // 24
{ true,  "a*$",                       "Xaa" }, // 25
{ true,  "[a-h]+",                    "abcdefghxxx" }, // 26
{ false, "[a-h]+",                    "ABCDEFGH" }, // 27
{ true,  "[A-H]+",                    "ABCDEFGH" }, // 28
{ false, "[A-H]+",                    "abcdefgh" }, // 29
{ true,  "[^\\s]+",                   "abc def" }, //30
{ true,  "[^fc]+",                    "abc def" },  // 31
{ true,  "[^d\\sf]+",                 "abc def" },  // 32
{ true,  "\n",                        "abc\ndef" }, // 33
{ true,  "b.\\s*\n",                  "aa\r\nbb\r\ncc\r\n\r\n" }, // 34
{ true,  ".*c",                       "abcabc" }, // 35
{ true,  ".+c",                       "abcabc" }, // 36
{ true,  "[b-z].*",                   "ab" }, // 37
{ true,  "b[k-z]*",                   "ab" }, // 38
{ false, "[0-9]",                     "  - " }, // 39
{ true,  "[^0-9]",                    "  - " }, // 40
{ true,  "0|",                        "0|" },   // 41
{ false, "\\d\\d:\\d\\d:\\d\\d",      "0s:00:00" }, // 42
{ false, "\\d\\d:\\d\\d:\\d\\d",      "000:00" }, // 43
{ false, "\\d\\d:\\d\\d:\\d\\d",      "00:0000" }, // 44
{ false, "\\d\\d:\\d\\d:\\d\\d",      "100:0:00" }, // 45
{ false, "\\d\\d:\\d\\d:\\d\\d",      "00:100:00" }, // 46
{ false, "\\d\\d:\\d\\d:\\d\\d",      "0:00:100" }, // 47
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "0:0:0" }, // 48
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "0:00:0" }, // 49
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "0:0:00" }, //50
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "00:0:0" }, // 51
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "00:00:0" }, // 52
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "00:0:00" }, // 53
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "0:00:00" }, // 54
{ true,  "\\d\\d?:\\d\\d?:\\d\\d?",   "00:00:00" }, // 55
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "Hello world !" }, // 56
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "hello world !" }, // 57
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "Hello World !" }, // 58
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "Hello world!   " }, // 59
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "Hello world  !" }, // 60
{ true,  "[Hh]ello [Ww]orld\\s*[!]?", "hello World    !" }, // 61
{ false, "\\d\\d?:\\d\\d?:\\d\\d?",   "a:0" },               // 62
{ true,  "[^\\w][^-1-4]",     ")T"          },               // 63
{ true,  "[^\\w][^-1-4]",     ")^"          },               // 64
{ true,  "[^\\w][^-1-4]",     "*)"          },               // 65
{ true,  "[^\\w][^-1-4]",     "!."          },                // 66
{ true,  "[^\\w][^-1-4]",     " x"          },               // 67
{ true,  "[^\\w][^-1-4]",     "$b"          },               // 68
{ true,  ".?bar",                      "real_bar" },         // 69
{ false, ".?bar",                      "real_foo" },          // 70
{ false, "X?Y",                        "Z" },                // 71
{ true, ".*", "aabbccddee"},	// 72
{ true, ".*d", "aabbccddee"}, // 73
{ true, ".*dd", "aabbccddee"} // 74
};
char Test2[] = 
"If you have an interest then please give the code a whirl. "
"It can be found on GitHub with versions for Arduino and more general"
"C / C++ environments. Happy to debate any issues you might have with the "
"results – some might track down bugs and other issues could lead to "
"revised interpretations of the rules.";
