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
  Object * o11 = p11.object();
  ASSERT(TOLERANCE > std::abs(o11->get_d() - 13.5));
  delete o11;
  Parser p12("5 + 7 + 1");
  Object * o12 = p12.object();
  ASSERT(13 == o12->get_i());
  delete o12;
  try {
    Parser p13("3.1415e0 + \"badvalue\"");
    std::cout << p13.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 2: Test '-' operator and associated exceptions
  Parser p21("-9 - 6 - 1");
  Object * o21 = p21.object();
  ASSERT(-16 == o21->get_i());
  delete o21;
  Parser p22("6 - 2.2 - 1.1");
  Object * o22 = p22.object();
  ASSERT(TOLERANCE > std::abs(o22->get_d() - 2.7));
  delete o22;
  try {
    Parser p23("6 - [\"badvalue1\",\"badvalue2\"]");
    std::cout << p23.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 3: Test '*' operator and associated exceptions
  Parser p31("3 * 2.5 * -2");
  Object * o31 = p31.object();
  ASSERT(TOLERANCE > std::abs(o31->get_d() + 15.0));
  delete o31;
  Parser p32("1 * 2 * 3");
  Object * o32 = p32.object();
  ASSERT(6 == o32->get_i());
  delete o32;
  try {
    Parser p33("9.6 * {\"badkey\":\"badvalue\"}");
    std::cout << p33.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 4: Test '/' operator and associated exceptions
  Parser p41("7.5 / 3 / 5");
  Object * o41 = p41.object();
  ASSERT(TOLERANCE > std::abs(o41->get_d() - 0.5));
  delete o41;
  Parser p42("8 / 2 / -4");
  Object * o42 = p42.object();
  ASSERT(-1 == o42->get_i());
  delete o42;
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
  try {
    Parser p45("6.36e4 / true");
    std::cout << p45.object()->get_i() << std::endl;
  } catch (ParserException &e) {
    std::cout << e.what() << std::endl;
  }

  // Test set 5: Test '%' operator and associated exceptions
  Parser p51("-5 % 2");
  Object * o51 = p51.object();
  ASSERT(-1 == o51->get_i());
  delete o51;
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
  try {
    Parser p54("5 % null");
    std::cout << p54.object()->get_i() << std::endl;
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
  Object * o = p.object();
  std::cout << o->stringify() << std::endl;
  delete o;

  SUCCEED;
}
