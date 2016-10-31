#include <iostream>
#include <cmath>
#include "json.hh"
#include "test.hh"

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // HASH COPY CONSTRUCTOR TESTS
  // This file tests the Hash class copy constructor
  // and the keys() method which returns an Array of keys
  // of type String

  // Test 1: Check if all keys in hash are returned by keys() method
  Hash h;
  Array key;
  Number n1(1);
  Number n2(2);
  Number n3(3);
  h.set("first", n1);
  h.set("second", n2);
  h.set("third", n3);
  key = h.keys();
  std::cout << std::endl << "hash keys: " << key.stringify() << std::endl;
  try {
    // Using '==' with doubles can return wrong results
    // due to rounding errors. Checking the doubles are close
    // to each other within some tolerance value is a better 
    // way to compare them
    ASSERT(TOLERANCE > std::abs(h.get("first")->get_num() - n1.get_num()));
    ASSERT(TOLERANCE > std::abs(h.get("second")->get_num() - n2.get_num()));
    ASSERT(TOLERANCE > std::abs(h.get("third")->get_num() - n3.get_num()));
  } catch (Object_Exception &e) {
    std::cout << e.what();
    FAIL;
  }

  // Test 2: Check a hash is copied successfully
  Hash h1(h);
  std::cout << "Original hash:" << h.stringify() << std::endl;
  std::cout << "Copied hash:" << h1.stringify() << std::endl;
  try {
    // Using '==' with doubles can return wrong results
    // due to rounding errors. Checking the doubles are close
    // to each other within some tolerance value is a better 
    // way to compare them
    ASSERT(TOLERANCE > std::abs(h1.get("first")->get_num() - n1.get_num()));
    ASSERT(TOLERANCE > std::abs(h1.get("second")->get_num() - n2.get_num()));
    ASSERT(TOLERANCE > std::abs(h1.get("third")->get_num() - n3.get_num()));
  } catch (Object_Exception &e) {
    std::cout << e.what();
    FAIL;
  }
  SUCCEED;
}
