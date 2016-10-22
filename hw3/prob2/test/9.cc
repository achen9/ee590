#include "test.hh"
#include "complex.hh"
#include <cmath>

#define TOLERANCE 0.0001
#define PI 3.14159

int main ( int argc, char * argv[] ) {

  // RAISING e TO THE POWER OF A GIVEN COMPLEX NUMBER
  // This file tests the exp() method to raise e to the power
  // of the complex number that calls it

  // TEST 1: Check e^(j*pi) ~= -1
  complex x1(0, PI);
  complex x = x1.exp();
  ASSERT(TOLERANCE > std::abs(x.re() + 1) && TOLERANCE > std::abs(x.im() - 0));

  // TEST 2: Check e^(3+4j) ~= -13.12878-15.20078j
  complex y1(3, 4);
  complex y = y1.exp();
  ASSERT(TOLERANCE > std::abs(y.re() + 13.12878) && TOLERANCE > std::abs(y.im() + 15.20078));

  // TEST 3: Check e^(0-0j) ~= 1
  complex z1(0, -0);
  complex z = z1.exp();
  ASSERT(TOLERANCE > std::abs(z.re() - 1) && TOLERANCE > std::abs(z.im() - 0));
  SUCCEED;
}
