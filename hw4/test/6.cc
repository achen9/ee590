#include <iostream>
#include <cmath>
#include "json.hh"
#include "test.hh"

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // STRING CLASS METHODS TESTS
  // This file tests the methods defined in the String class

  // Test set 1: Check String objects can be constructed
  String s1;
  String s2("This is s2");
  ASSERT(s1.get_str() == "");
  ASSERT(s2.get_str() == "This is s2");

  // Test set 2: Check String objects can be copied
  String s3(s2);
  String s4 = s2;
  ASSERT(s3.get_str() == "This is s2");
  ASSERT(s4.get_str() == "This is s2");

  // Test set 3: Check String objects can be cloned
  s1.set("This is s1's clone");
  String * s1clone = s1.clone();
  s1.set("This is s1");
  ASSERT(s1clone->get_str() == "This is s1's clone");
  ASSERT(s1.get_str() == "This is s1");

  // Test set 4: Check String objects can be stringified
  std::cout << std::endl << "s1 stringified: " << s1.stringify() << std::endl;

  SUCCEED;
}
