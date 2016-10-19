#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // OVERLOAD '=' TESTS
  // This file tests all '=' overloads by building a fraction with each and then
  // testing that the overload worked.

  // TEST 1: Check if 5 can be assigned as whole number
  fraction x = 5;
  ASSERT(5 == x.num() && 1 == x.den());

  // TEST 2: Check if -33 can be assigned as whole number
  fraction y = -33;
  ASSERT(-33 == y.num() && 1 == y.den());
  
  SUCCEED;
}
