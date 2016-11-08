#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hh"
#include "test.hh"

#define OUTPUT_PER_ROW 5

int main ( int argc, char * argv[] ) {
  // TOKENIZER NEXT() METHOD TESTS
  // This file tests the Tokenizer next() method to 
  // make sure it recognizes '+', '-', '*', '/', '%',
  // '(', and ')' as punctuation

  std::ifstream inFile;
  // open the input file. data3.json contains the example
  // JSON shown in hw5 problem 3.
  inFile.open("data3.json");

  std::stringstream strStream;
  strStream << inFile.rdbuf(); //read the file
  std::string str = strStream.str(); //str holds the content of the file

  Tokenizer tok(str);
  int i = 1;
  while ( !tok.eof() ) {
    Token T = tok.eat();
    std::cout << T;
    // Places more tokens per line. Shortens the height of the output to
    // the console
    if (0 == i % OUTPUT_PER_ROW) {
      std::cout << std::endl;
    }
    // Test 1: Spot check tokens for punctuation
    switch (i) {
      case 5: 
        ASSERT('-' == T.punct_val());
        break;
      case 7:
        ASSERT('*' == T.punct_val());
        break;
      case 8:
        ASSERT('(' == T.punct_val());
        break;
      case 10:
        ASSERT('+' == T.punct_val());
        break;
      case 12:
        ASSERT(')' == T.punct_val());
        break;
      case 13:
        ASSERT('/' == T.punct_val());
        break;
      case 20:
        ASSERT('%' == T.punct_val());
        break;
      default:
        break;
    }
    i++;
  }
  
  SUCCEED;
}
