#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // INPUT JSON FILE TESTS
  // This file takes an input JSON file and runs the parser on it
  // to return a true JSON object

  // Test 1: Run parser on sample JSON
  if (2 != argc) {
    std::cout << "Incorrect number of input arguments given. Expecting 1 input." << std::endl;
    return -1;
  }
  std::ifstream inFile;
  // open the input file. data3.json contains the example
  // JSON shown in hw5 problem 3.
  inFile.open(argv[1]);
  if (inFile.is_open()) {
    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file

    Parser p(str);
    std::cout << p.object()->stringify() << std::endl;
    inFile.close();
    SUCCEED;
  } else {
    std::cout << "Failed to open file: \"" << argv[1] << "\"" << std::endl;
    FAIL;
  }
}
