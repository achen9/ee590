#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS
  // This file tests all constructors by building a fraction with each and then
  // testing that the fraction is correct using the getters.

  // TEST 1: Check if 3/4 can be assigned to the fraction
  fraction x(3, 4);
  ASSERT(3 == x.num() && 4 == x.den());

  // TEST 2: Check if -2/-30 can be assigned to the fraction
  fraction y(-2, -30);
  ASSERT(-2 == y.num() && -30 == y.den());
  
  // TEST 3: Check fraction will throw error if denominator is zero
  try {
    fraction y(2, 0);
  } catch (fraction_exception e) {
    SUCCEED;
  }
  FAIL;
}
