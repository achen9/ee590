#include "test.hh"
#include "complex.hh"
#include <math.h>

#define TOLERANCE 0.00001

int main ( int argc, char * argv[] ) {

  // UNARY '-' OPERATOR TESTS
  // This file tests the unary '-' operator overload

  // TEST 1: Check -(3.22+4.11j) ~= -3.22-4.11j
  complex x1(3.22, 4.11);
  complex x = -x1;
  ASSERT(TOLERANCE > abs(x.re() + 3.22) && TOLERANCE > abs(x.im() + 4.11));

  // TEST 2: Check -(4.21+3.85j) + 4.21+3.85j ~= 0+0j
  complex y1(4.21, 3.85);
  complex y = -y1 + y1;
  ASSERT(TOLERANCE > abs(y.re() - 0.0) && TOLERANCE > abs(y.im() - 0.0));

  // Test 3: Check -(-2.34+0.0j) ~= 2.34+0.0j
  complex z1(-2.34, -0.0);
  complex z = -z1;
  ASSERT(TOLERANCE > abs(z.re() - 2.34) && TOLERANCE > abs(z.im() - 0.0));

  SUCCEED;
}
