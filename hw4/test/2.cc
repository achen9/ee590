#include <iostream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // RUNTIME ERROR TESTS
  // This file tests the Object_Exception class 
  // to ensure it is thrown during a runtime error

  /* // Test set 1: Check Object class methods throw
  // Object_Exception errors when trying to call them
  int exceptions = 0;
  Object o;
  try {
    o.get();
  } catch (Object_Exception e) {
    std::cout << e;
    exceptions++;
  }
  ASSERT(1 == exceptions);
  try {
    o.get("Test");
  } catch (Object_Exception e) {
    std::cout << e;
    exceptions++;
  }
  ASSERT(2 == exceptions);
  try {
    o.get(5);
  } catch (Object_Exception e) {
    std::cout << e;
    exceptions++;
  }
  ASSERT(3 == exceptions);
  */ 
  // Test set 2: Check Array.get(out of bounds) 
  // throws an exception
  int exceptions = 3;
  Array a;
  try {
    a.get(12);
  } catch (Object_Exception &e) {
    std::cout << std::endl << e.what() << std::endl;
    exceptions++;
  }
  ASSERT(4 == exceptions);

  // Test set 3: Check Hash.get(non existing key)
  // throws an exception
  Hash h;
  Number n(1);
  h.set("first", n);
  h.set("second", h);
  try {
    h.get("third");
  } catch (Object_Exception &e) {
    std::cout << e.what();
    SUCCEED;
  }
  FAIL;
}
