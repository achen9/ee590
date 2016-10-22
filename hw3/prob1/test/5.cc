#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION TESTS
  // This file tests the add(), sub(), mult(), and div() methods and their
  // corresponding operator overloads

  // TEST 1: Add : 1/2 + 1/3 = 5/6
  fraction x1(1, 2);
  fraction x2(1, 3);
  fraction x = x1 + x2;
  ASSERT(5 == x.num() && 6 == x.den());

  // TEST 2: Add : (1/2 + 2/-4) + 5/6 = 5/6
  fraction s1(1, 2);
  fraction s2(2, -4);
  fraction s = (s1 + s2) + x;
  ASSERT(5 == s.num() && 6 == s.den());

  // TEST 3: Subtract : 2/4 - 2/3 = -1/6
  fraction y1(2, 4);
  fraction y2(2, 3);
  fraction y = y1 - y2;
  ASSERT(-1 == y.num() && 6 == y.den());

  // TEST 4: Multiply : -4/5 * 3/4 = -3/5
  fraction w1(-4, 5);
  fraction w2(3, 4);
  fraction w = w1 * w2;
  ASSERT(-3 == w.num() && 5 == w.den());

  // TEST 5: Divide : (-5/7) / (-6/7) = 5/6
  fraction z1(-5, 7);
  fraction z2(-6, 7);
  fraction z = z1 / z2;
  ASSERT(5 == z.num() && 6 == z.den());
  
  // TEST 6: Divide by zero : (2/3) / (0/2) = error
  fraction r1(2, 3);
  fraction r2(0, 2);
  try {
    fraction r = r1 / r2;
  } catch(fraction_exception &e) {
    SUCCEED;
  }
  FAIL;
}
