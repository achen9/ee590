#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // RELATIONS OVERLOAD TEST
  // This file tests relations '==', '!=', '<', '>', '<=', '>=' overloads

  // TEST 1: 2/3 == 6/9 -> true
  fraction x1(2, 3);
  fraction x2(6, 9);
  ASSERT(x1 == x2);

  // TEST 2: -2/-3 == 3/4 -> false
  fraction x3(-2, -3);
  fraction x4(3, 4);
  ASSERT(!(x3 == x4));

  // TEST 2: -2/-3 != 3/4 -> true
  ASSERT(x3 != x4);

  // TEST 4: 2/3 != 6/9 -> false
  ASSERT(!(x1 != x2));

  // TEST 5: -2/-3 < 3/4 -> true
  ASSERT(x3 < x4);

  // TEST 6: 3/4 < 2/3 -> false
  ASSERT(!(x4 < x1));

  // TEST 7: 3/4 > 2/-3 -> true
  fraction x5(2, -3);
  ASSERT(x4 > x5);

  // TEST 8: -2/3 > 3/4 -> false
  ASSERT(!(-x1 > x4));

  // TEST 9: 2/3 <= 6/9 -> true
  ASSERT(x1 <= x2);

  // TEST 10: 2/3 <= -2/3 -> false
  ASSERT(!(x1 <= -x1));
  
  // TEST 11: 2/3 >= 6/9 -> true
  ASSERT(x1 >= x2);

  // TEST 12: -8/3 >= 2/3 -> false
  fraction x6(-8, 3);
  ASSERT(!(x6 >= x1));
  
  SUCCEED;
}
