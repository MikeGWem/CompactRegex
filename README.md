# CompactRegex
A compact Regular Expression in C++ for memory restricted applications.

There is a blog post for background material at 

There are versions here for 8 bit (and other) Arduinos and more general C++ applications.

The aim was to develop a compact regular expression class that had a minimal impact upon
working memory (the SRAM component on an Arduino). The range of options is therefore limited
but hopefuly enough to meet most needs.

|*Regex component* | *Meaning*|
|------------|----------|
| ^  |	Start anchor |
| $  |	End anchor   |
| c	 | match a character literal |
| \d | match digits 0 to 9 |
| \D | matched if not digit |
| \w | match alphanumeric char |
| \W | matched if not alphanumeric |
| \s | matches whitespace |
| \S | match if not whitespace |
| . (full stop) | match any character not a line feed (\n) |
| *  | match zero or more of previous construct |
| +  | match one or more of previous construct |
| ?  | match zero or one of previous construct |
| [a-z] or [0-9A-H] |match to one or more character ranges |
| [abcd] | match to any one of a set of characters |
| [^a-z] | match if not in range (eg. not a to z) |
| [^defg] | match if not in list |


Lists of characters within square brackets can contain meta characters (such as \d). Characters such as ‘*’ or ‘?’ need to be escaped if they are outside of a list and should be matched just as a character. There is also support for a match to start at any position within the target text and a facility to return the length of any matched text.

The usage starts by creating an instance of the Regex class passing a pointer to a regular expression to the constructor. Then the match() method is passed a pointer to a target char array. The method will return the position of the first match in the target string or -1 if no match is found. The match method can also be passed an additional integer argument to set the point in the target string for the search for a match to begin (zero based). The class getMatchLength() method will return the number of characters in the target string that were matched by the regular expression.

*Further work*


There is no immediate intention to tackle the following but do feel free to wade in if you feel like it.

Numeric quantifiers could be added.

| *Quantifier* | *Meaning* |
|-----|-----|
| {3} | match exactly 3 times |
| {2, 4} | match between 2 and 4 times |
| {2,} | match 2 or more times |

The union component of the RE struct could have an array of two (uint8_t) unsigned 8 bit integers added which would allow plenty of scope without increasing the size of the struct on 8 bit boards.

Another tweak could be to allow lists and ranges to be mixed in the same class (e.g. [ext0-9]. It makes sense as a range is just shorthand for a number of items in the list.


