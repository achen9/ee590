#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // UNARY '-' OPERATOR TESTS
  // This file tests the unary '-' operator overload

  // TEST 1: negate 3/5
  fraction x1(3, 5);
  fraction x = -x1;
  ASSERT(-3 == x.num() && 5 == x.den());

  // TEST 2: negate -4/6
  fraction y1(-4, 6);
  fraction y = -y1;
  ASSERT(4 == y.num() && 6 == y.den());

  // TEST 3: negate 2/-5
  fraction w1(2, -5);
  fraction w = -w1;
  ASSERT(2 == w.num() && 5 == w.den());

  // TEST 4: negate -3/-7
  fraction z1(-3, -7);
  fraction z = -z1;
  ASSERT(-3 == z.num() && 7 == z.den());
  
  SUCCEED;
}
