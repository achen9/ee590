#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // CONJUGATE TESTS
  // This file tests the conjugate() method

  // TEST 1: Check conjugate of 3.22+4.11j -> 3.22-4.11j
  complex x1(3.22,4.11);
  complex x = x1.conjugate();
  ASSERT(3.22 == x.re() && -4.11 == x.im());

  // TEST 2: Check conjugate of -3.44+0j -> -3.44+0j
  complex y1 = -3.44;
  complex y = y1.conjugate();
  ASSERT(-3.44 == y.re() && 0.0 == y.im());

  // TEST 3: Check conjugate of -2.89-6.033j -> -2.89+6.033j
  complex z1(-2.89, -6.033);
  complex z = z1.conjugate();
  ASSERT(-2.89 == z.re() && 6.033 == z.im());
  
  SUCCEED;
}
