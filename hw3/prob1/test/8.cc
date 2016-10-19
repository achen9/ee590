#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // FRACTION POWER TESTS
  // This file tests pow() method

  // TEST 1: (2/3)^3 = 8/27
  fraction x1(2, 3);
  fraction x = x1.power(3);
  ASSERT(8 == x.num() && 27 == x.den());

  // TEST 2: (3/-5)^0 = 1/1
  fraction y1(3, -5);
  fraction y = y1.power(0);
  ASSERT(1 == y.num() && 1 == y.den());

  // TEST 3: (4/-8)^-2 = 4/1
  fraction z1(4, -8);
  fraction z = z1.power(-2);
  ASSERT(4 == z.num() && 1 == z.den());  
  
  SUCCEED;
}
