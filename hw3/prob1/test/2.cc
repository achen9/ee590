#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // COPY CONSTRUCTOR TESTS
  // This file tests all copy constructors by building a fraction with each and then
  // testing that the copied fraction is correct using the getters.

  // TEST 1: Check if 3/4 can be assigned to the fraction
  fraction x1(3, 4);
  fraction x2(x1);
  ASSERT(3 == x2.numerator() && 4 == x2.denominator());

  // TEST 2: Check if both numerator and denominator are negative, they become positive
  fraction y1(-2, -30);
  fraction y2(y1);
  ASSERT(-2 == y2.numerator() && -30 == y2.denominator());
  
  SUCCEED;
}
