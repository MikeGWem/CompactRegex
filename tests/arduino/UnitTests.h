#include <Arduino.h>


bool const match[] PROGMEM = {
true, true, true, false, true, false,false,false,true, true, false,true, 
true, false,true, false,false,true, true, true, true, false,true, true, 
true, true, false,true, false,true, true, true, true, true, true, true, 
true, true, false,true, true, false,false,false,false,false,false,true, 
true, true, true, true, true, true, true, true, true, true, true, true, 
true, false,true, true, true, true, true, true, true, false,false,true, true, true};

 const char rx1[] PROGMEM = "\\d";
 const char rx2[] PROGMEM = "\\w+";                
 const char rx3[] PROGMEM = "\\s";                   
 const char rx4[] PROGMEM = "\\S";                      
 const char rx5[] PROGMEM = "[\\s]";
 const char rx6[] PROGMEM = "[\\S]";                
 const char rx7[] PROGMEM = "\\D";       
 const char rx8[] PROGMEM = "\\W+";
 const char rx9[] PROGMEM = "[0-9]+";                 
 const char rx10[] PROGMEM = "\\D";                   
 const char rx11[] PROGMEM = "\\d";                    
 const char rx12[] PROGMEM = "[^\\w]";                  
 const char rx13[] PROGMEM = "[\\W]";                  
 const char rx14[] PROGMEM = "[\\w]";                  
 const char rx15[] PROGMEM = "[^\\d]";                   
 const char rx16[] PROGMEM = "[\\d]";                   
 const char rx17[] PROGMEM = "[^\\D]";                   
 const char rx18[] PROGMEM = "[\\D]";                   
 const char rx19[] PROGMEM = "^.*\\\\.*$";               
 const char rx20[] PROGMEM = "^[\\+-]*[\\d]+$";          
 const char rx21[] PROGMEM = "[abc]";          
 const char rx22[] PROGMEM = "[abc]";                    
 const char rx23[] PROGMEM = "[1-5]+";                   
 const char rx24[] PROGMEM = "[.2]";                   
 const char rx25[] PROGMEM = "a*$";                     
 const char rx26[] PROGMEM = "[a-h]+";                   
 const char rx27[] PROGMEM = "[a-h]+";                   
 const char rx28[] PROGMEM = "[A-H]+";                   
 const char rx29[] PROGMEM = "[A-H]+";                   
 const char rx30[] PROGMEM = "[^\\s]+";                  
 const char rx31[] PROGMEM = "[^fc]+";                  
 const char rx32[] PROGMEM = "[^d\\sf]+";                
 const char rx33[] PROGMEM = "\n";                
 const char rx34[] PROGMEM = "b.\\s*\n";                 
 const char rx35[] PROGMEM = ".*c";                 
 const char rx36[] PROGMEM = ".+c";                      
 const char rx37[] PROGMEM = "[b-z].*";                  
 const char rx38[] PROGMEM = "b[k-z]*";              
 const char rx39[] PROGMEM = "[0-9]";                  
 const char rx40[] PROGMEM = "[^0-9]";                   
 const char rx41[] PROGMEM = "0|";                   
 const char rx42[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";
 const char rx43[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";     
 const char rx44[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";     
 const char rx45[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";     
 const char rx46[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";     
 const char rx47[] PROGMEM = "\\d\\d:\\d\\d:\\d\\d";     
 const char rx48[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx49[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx50[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx51[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx52[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx53[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx54[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx55[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";  
 const char rx56[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx57[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx58[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx59[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx60[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx61[] PROGMEM = "[Hh]ello [Ww]orld\\s*[!]?";
 const char rx62[] PROGMEM = "\\d\\d?:\\d\\d?:\\d\\d?";
 const char rx63[] PROGMEM = "[^\\w][^-1-4]";
 const char rx64[] PROGMEM = "[^\\w][^-1-4]"; 
 const char rx65[] PROGMEM = "[^\\w][^-1-4]"; 
 const char rx66[] PROGMEM = "[^\\w][^-1-4]";  
 const char rx67[] PROGMEM = "[^\\w][^-1-4]";  
 const char rx68[] PROGMEM = "[^\\w][^-1-4]";
 const char rx69[] PROGMEM = ".?bar";           
 const char rx70[] PROGMEM = ".?bar";                   
 const char rx71[] PROGMEM = "X?Y";                   
 const char rx72[] PROGMEM = ".*";
 const char rx73[] PROGMEM = ".*d";
 const char rx74[] PROGMEM = ".*dd";
 
 const char* const regxs[] PROGMEM = {
rx1, rx2, rx3, rx4, rx5, rx6, rx7, rx8, rx9, rx10,
rx11,rx12,rx13,rx14,rx15,rx16,rx17,rx18,rx19,rx20,
rx21,rx22,rx23,rx24,rx25,rx26,rx27,rx28,rx29,rx30,
rx31,rx32,rx33,rx34,rx35,rx36,rx37,rx38,rx39,rx40,
rx41,rx42,rx43,rx44,rx45,rx46,rx47,rx48,rx49,rx50,
rx51,rx52,rx53,rx54,rx55,rx56,rx57,rx58,rx59,rx60,
rx61,rx62,rx63,rx64,rx65,rx66,rx67,rx68,rx69,rx70,
rx71,rx72,rx73,rx74};

const char tx1[] PROGMEM = "5";
const char tx2[] PROGMEM = "hej";
const char tx3[] PROGMEM = "\t \n";
const char tx4[] PROGMEM = "\t \n";
const char tx5[] PROGMEM = "\t \n";
const char tx6[] PROGMEM = "\t \n";
const char tx7[] PROGMEM = "5";
const char tx8[] PROGMEM = "hej";
const char tx9[] PROGMEM = "12345";
const char tx10[] PROGMEM = "hej";
const char tx11[] PROGMEM = "hej";
const char tx12[] PROGMEM = "\\";
const char tx13[] PROGMEM = "\\";
const char tx14[] PROGMEM = "\\";
const char tx15[] PROGMEM = "d";
const char tx16[] PROGMEM = "d";
const char tx17[] PROGMEM = "d";
const char tx18[] PROGMEM = "d";
const char tx19[] PROGMEM = "c:\\Tools";
const char tx20[] PROGMEM = "+27";
const char tx21[] PROGMEM = "1c2";
const char tx22[] PROGMEM = "1C2";
const char tx23[] PROGMEM = "0123456789";
const char tx24[] PROGMEM = "1C2";
const char tx25[] PROGMEM = "Xaa";
const char tx26[] PROGMEM = "abcdefghxxx";
const char tx27[] PROGMEM = "ABCDEFGH";
const char tx28[] PROGMEM = "ABCDEFGH";
const char tx29[] PROGMEM = "abcdefgh";
const char tx30[] PROGMEM = "abc def";
const char tx31[] PROGMEM = "abc def";
const char tx32[] PROGMEM = "abc def";
const char tx33[] PROGMEM = "abc\ndef";
const char tx34[] PROGMEM = "aa\r\nbb\r\ncc\r\n\r\n";
const char tx35[] PROGMEM = "abcabc";
const char tx36[] PROGMEM = "abcabc";
const char tx37[] PROGMEM = "ab";
const char tx38[] PROGMEM = "ab";
const char tx39[] PROGMEM = "  - ";
const char tx40[] PROGMEM = "  - ";
const char tx41[] PROGMEM = "0|";
const char tx42[] PROGMEM = "0s:00:00";
const char tx43[] PROGMEM = "000:00";
const char tx44[] PROGMEM = "00:0000";
const char tx45[] PROGMEM = "100:0:00";
const char tx46[] PROGMEM = "00:100:00";
const char tx47[] PROGMEM = "0:00:100";
const char tx48[] PROGMEM = "0:0:0";
const char tx49[] PROGMEM = "0:00:0";
const char tx50[] PROGMEM = "0:0:00";
const char tx51[] PROGMEM = "00:0:0";
const char tx52[] PROGMEM = "00:00:0";
const char tx53[] PROGMEM = "00:0:00";
const char tx54[] PROGMEM = "0:00:00";
const char tx55[] PROGMEM = "00:00:00";
const char tx56[] PROGMEM = "Hello world !";
const char tx57[] PROGMEM = "hello world !";
const char tx58[] PROGMEM = "Hello World !";
const char tx59[] PROGMEM = "Hello world!   ";
const char tx60[] PROGMEM = "Hello world  !";
const char tx61[] PROGMEM = "hello World    !";
const char tx62[] PROGMEM = "a:0";
const char tx63[] PROGMEM = ")T";         
const char tx64[] PROGMEM = ")^";         
const char tx65[] PROGMEM = "*)";         
const char tx66[] PROGMEM = "!.";         
const char tx67[] PROGMEM = " x";         
const char tx68[] PROGMEM = "$b";         
const char tx69[] PROGMEM = "real_bar";
const char tx70[] PROGMEM = "real_foo";
const char tx71[] PROGMEM = "Z";      
const char tx72[] PROGMEM = "aabbccddee";
const char tx73[] PROGMEM = "aabbccddee";
const char tx74[] PROGMEM = "aabbccddee";
 
const char* const text[] PROGMEM = {
tx1, tx2, tx3, tx4, tx5, tx6, tx7, tx8, tx9, tx10,
tx11,tx12,tx13,tx14,tx15,tx16,tx17,tx18,tx19,tx20,
tx21,tx22,tx23,tx24,tx25,tx26,tx27,tx28,tx29,tx30,
tx31,tx32,tx33,tx34,tx35,tx36,tx37,tx38,tx39,tx40,
tx41,tx42,tx43,tx44,tx45,tx46,tx47,tx48,tx49,tx50,
tx51,tx52,tx53,tx54,tx55,tx56,tx57,tx58,tx59,tx60,
tx61,tx62,tx63,tx64,tx65,tx66,tx67,tx68,tx69,tx70,
tx71,tx72,tx73,tx74};

const char Test2[] PROGMEM = 
"If the these are in the text then the text is these.";
