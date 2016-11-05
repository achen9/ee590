#include <iostream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // TOKENIZER NUMBER() METHOD TESTS
  // This file tests the Tokenizer number() method to 
  // make sure it recognizes negative values and scientific
  // notation

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");
  //Tokenizer tok("{ \"a\": [0,1,2], \"b\": { \"c\": 0 } }");

  // Test 1: Check negative values are recognized as tokens
  Tokenizer tok("[5.30,-6.55,-5..35,96-5.6]");
  std::cout << "Test 1..." << std::endl;
  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  // Test 2: Check scientific notation values are recognized as tokens
  Tokenizer tok2("[5.2e-6,6E-08,1e-6.2.5E9-5");
  std::cout << "Test 2..." << std::endl;
  while (!tok2.eof()) {
    std::cout << tok2.eat() << std::endl;
  }
  
  // Test 3: Check exceptions are thrown when invalid numbers are
  // entered
  Tokenizer tok3("[e12]");
  try {
    std::cout << "Test 3..." << std::endl;
    while (!tok3.eof()) {
      std::cout << tok3.eat() << std::endl;
    }
  } catch (TokenizerException &e) {
    std::cout << e.what() << std::endl;
  }
  Tokenizer tok4("[3e-9--2]");
  try {
    while (!tok4.eof()) {
      std::cout << tok4.eat() << std::endl;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "std::invalid_argument in " << e.what() << std::endl;
    SUCCEED;
  }
  FAIL;
}
