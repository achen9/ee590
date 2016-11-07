#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
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
