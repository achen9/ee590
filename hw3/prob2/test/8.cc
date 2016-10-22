#include "test.hh"
#include "complex.hh"
#include <math.h>

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {

  // RAISING COMPLEX TO AN INTEGER POWER TESTS
  // This file tests the power() method to raise a complex number
  // to an integer power

  // TEST 1: Check (3+4j)^5 ~= -237-3116j
  complex x1(3, 4);
  complex x = x1.power(5);
  ASSERT(TOLERANCE > abs(x.re() + 237) && TOLERANCE > abs(x.im() + 3116));

  // TEST 2: Check (1+j)^-2 ~= -j/2
  complex y1(1,1);
  complex y = y1.power(-2);
  ASSERT(TOLERANCE > abs(y.re() - 0) && TOLERANCE > abs(y.im() + 0.5));

  // TEST 3: Check (1.23+3.25j)^0 ~= 1
  complex z1(1.23,3.25);
  complex z = z1.power(0);
  ASSERT(TOLERANCE > abs(z.re() - 1) && TOLERANCE > abs(z.im() - 0));
  SUCCEED;
}
