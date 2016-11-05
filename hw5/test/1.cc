#include <iostream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");

  // Tokenizer tok("{ \"a\": [0,1,2], \"b\": { \"c\": 0 } }");

  Tokenizer tok("[5.30,-6.55,6.9,-5..35,96-5.6]");

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  return 0;

}
