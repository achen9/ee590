#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "json.hh"
#include "test.hh"

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // PARSER CLASS METHOD TESTS
  // This file tests the Parser class methods 

  // Test set 1: Test '+' operator and associated exceptions
  Parser p11("5.2 + 6 + 2.3");
  ASSERT(TOLERANCE > std::abs(p11.object()->get_d() - 13.5));
  Parser p12("5 + 7 + 1");
  ASSERT(13 == p12.object()->get_i());

  // Test set 2: Test '-' operator and associated exceptions
  Parser p21("-9 - 6 - 1");
  ASSERT(-16 == p21.object()->get_i());
  Parser p22("6 - 2.2 - 1.1");
  ASSERT(TOLERANCE > std::abs(p22.object()->get_d() - 2.7));

  // Test set 3: Test '*' operator and associated exceptions
  Parser p31("3 * 2.5 * -2");
  ASSERT(TOLERANCE > std::abs(p31.object()->get_d() + 15.0));
  Parser p32("1 * 2 * 3");
  ASSERT(6 == p32.object()->get_i());

  // Test set 4: Test '/' operator and associated exceptions
  Parser p41("7.5 / 3 / 5");
  ASSERT(TOLERANCE > std::abs(p41.object()->get_d() - 0.5));
  Parser p42("8 / 2 / -4");
  ASSERT(-1 == p42.object()->get_i());
  try {
    Parser p43("9 / 0");
    std::cout << p43.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Parser p44("10.2 / -0.0");
    std::cout << p44.object()->get_d() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 5: Test '%' operator and associated exceptions
  Parser p51("-5 % 2");
  ASSERT(-1 == p51.object()->get_i());
  try {
    Parser p52("6.2 % 3");
    std::cout << p52.object()->get_d() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Parser p53("4 % 0");
    std::cout << p53.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 6: Test parser on sample json
  std::ifstream inFile;
  // open the input file. data3.json contains the example
  // JSON shown in hw5 problem 3.
  inFile.open("data3.json");

  std::stringstream strStream;
  strStream << inFile.rdbuf(); //read the file
  std::string str = strStream.str(); //str holds the content of the file

  Parser p(str);
  std::cout << p.object()->stringify() << std::endl;

  SUCCEED;
}
