#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // REDUCE() TESTS
  // This file tests the reduce() method

  // TEST 1: Reduce 8/12 to 2/3
  fraction x(8, 12);
  fraction xr = x.reduce();
  ASSERT(2 == xr.num() && 3 == xr.den());

  // TEST 2: Reduce 9/-15 to -3/5
  fraction y(9, -15);
  fraction yr = y.reduce();
  ASSERT(-3 == yr.num() && 5 == yr.den());

  // TEST 3: Reduce -52/-13 to 4/1
  fraction w(-52, -13);
  fraction wr = w.reduce();
  ASSERT(4 == wr.num() && 1 == wr.den());

  // TEST 4: Reduce 0/203 to 0/203
  fraction z(0, 203);
  fraction zr = z.reduce();
  ASSERT(0 == zr.num() && 203 == zr.den());
  
  SUCCEED;
}
