#include <iostream>
#include <cmath>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // BOOLEAN CLASS METHODS TESTS
  // This file tests the methods defined in the Boolean class

  // Test set 1: Check Boolean objects can be constructed
  Boolean b1;
  Boolean b2(true);
  ASSERT(b1.get_bool() == false);
  ASSERT(b2.get_bool() == true);

  // Test set 2: Check Boolean objects can be copied
  Boolean b3(b2);
  Boolean b4 = b2;
  ASSERT(b3.get_bool() == true);
  ASSERT(b4.get_bool() == true);

  // Test set 3: Check Boolean objects can be cloned
  b1.set(true);
  Boolean * b1clone = b1.clone();
  b1.set(false);
  ASSERT(b1clone->get_bool() == true);
  ASSERT(b1.get_bool() == false);

  // Test set 4: Check Boolean objects can be stringified
  std::cout << std::endl << "b1 stringified: " << b1.stringify() << std::endl;

  SUCCEED;
}
