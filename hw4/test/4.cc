#include <iostream>
#include <cmath>
#include "json.hh"
#include "test.hh"

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // HASH SET METHOD DUPLICATE KEYS TESTS
  // This file tests the Hash set() method for duplicate 
  // keys. 

  // Test 1: Check if value of key can be overwritten
  Hash h;
  Number n1(1);
  Number n2(2);
  h.set("first", n1);
  h.set("second", n2);
  std::cout << std::endl << h.stringify() << std::endl;
  try {
    // Using '==' with doubles can return wrong results
    // due to rounding errors. Checking the doubles are close
    // to each other within some tolerance value is a better 
    // way to compare them
    ASSERT(TOLERANCE > std::abs(h.get("first")->get_num() - n1.get_num()));
    ASSERT(TOLERANCE > std::abs(h.get("second")->get_num() - n2.get_num()));
  } catch (Object_Exception &e) {
    std::cout << e.what();
    FAIL;
  }
  h.set("second", n1);
  h.set("third", n2);
  std::cout << h.stringify() << std::endl;
  try {
    // Using '==' with doubles can return wrong results
    // due to rounding errors. Checking the doubles are close
    // to each other within some tolerance value is a better 
    // way to compare them
    ASSERT(TOLERANCE > std::abs(h.get("second")->get_num() - n1.get_num()));
    ASSERT(TOLERANCE > std::abs(h.get("third")->get_num() - n2.get_num()));
  } catch (Object_Exception &e) {
    std::cout << e.what();
    FAIL;
  }
  SUCCEED;
}
