#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // COPY CONSTRUCTOR TESTS
  // This file tests all copy constructors by building a fraction with each and then
  // testing that the copied fraction is correct using the getters.

  // TEST 1: Check if 3/4 can be assigned to the fraction
  fraction x1(3, 4);
  fraction x2(x1);
  ASSERT(3 == x2.num() && 4 == x2.den());

  // Test 2: Check if '=' operator overload works on positive values
  fraction x3 = x1;
  ASSERT(3 == x3.num() && 4 == x3.den());

  // TEST 3: Check if -2/-30 can be assigned to the fraction
  fraction y1(-2, -30);
  fraction y2(y1);
  ASSERT(-2 == y2.num() && -30 == y2.den());

  // TEST 4: Check if '=' operator overload works on negative values
  fraction y3 = y1;
  ASSERT(-2 == y3.num() && -30 == y3.den());
  
  SUCCEED;
}
