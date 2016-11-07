#include <iostream>
#include <cmath>
#include "json.hh"
#include "test.hh"

#define OUTPUT_PER_ROW 5
#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // TOKENIZER NUMBER() METHOD TESTS
  // This file tests the Tokenizer number() method to 
  // make sure it recognizes negative values and scientific
  // notation

  // Test 1: Check scientific notation values are recognized as tokens
  Tokenizer tok("[5.2e-6,6E-08,1e-6.2.5E9-5");
  std::cout << "Test 1..." << std::endl;
  int i = 1;
  while (!tok.eof()) {
    Token T = tok.eat();
    std::cout << T;
    // Places more tokens per line. Shortens the height of the output to
    // the console
    if (0 == i % OUTPUT_PER_ROW) {
      std::cout << std::endl;
    }
    // Spot check tokens
    switch (i) {
      case 2:
        // Using '==' with doubles can return wrong results
        // due to rounding errors. Checking the doubles are close
        // to each other within some tolerance value is a better 
        // way to compare them
        ASSERT(TOLERANCE > std::abs(T.dbl_val() - 5.2e-6));
        break;
      case 8:
        ASSERT(TOLERANCE > std::abs(T.dbl_val() - 5e8));
      default:
        break;
    }
    i++;
  }
  
  // Test 2: Check exceptions are thrown when invalid numbers are
  // entered
  Tokenizer tok2("[e12]");
  try {
    std::cout << "Test 2..." << std::endl;
    while (!tok2.eof()) {
      std::cout << tok2.eat() << std::endl;
    }
  } catch (TokenizerException &e) {
    std::cout << e.what() << std::endl;
    SUCCEED;
  }
  FAIL;
}
