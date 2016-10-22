#include "test.hh"
#include "complex.hh"
#include <cmath>

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {

  // RAISING COMPLEX TO AN INTEGER POWER TESTS
  // This file tests the pow() method to raise a complex number
  // to an integer power

  // TEST 1: Check (3+4j)^5 ~= -237-3116j
  complex x1(3, 4);
  complex x = x1.pow(5);
  ASSERT(TOLERANCE > std::abs(x.re() + 237) && TOLERANCE > std::abs(x.im() + 3116));

  // TEST 2: Check (1+j)^-2 ~= -j/2
  complex y1(1,1);
  complex y = y1.pow(-2);
  ASSERT(TOLERANCE > std::abs(y.re() - 0) && TOLERANCE > std::abs(y.im() + 0.5));

  // TEST 3: Check (1.23+3.25j)^0 ~= 1
  complex z1(1.23,3.25);
  complex z = z1.pow(0);
  ASSERT(TOLERANCE > std::abs(z.re() - 1) && TOLERANCE > std::abs(z.im() - 0));
  SUCCEED;
}
