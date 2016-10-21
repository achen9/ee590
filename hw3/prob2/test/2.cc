#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // COPY ONSTRUCTOR TESTS
  // This file tests all copy constructors by building a complex
  // number with each and then checking the complex number is correct
  // using the getters.

  // TEST 1: Check if 3+4j can be copied
  complex x1(3, 4);
  complex x(x1);
  ASSERT(3 == x.re() && 4 == x.im());

  // TEST 2: Check if 3+4j can be copied using '='
  complex x2 = x1;
  ASSERT(3 == x2.re() && 4 == x.im());

  // TEST 3: Check if -2-30j can be copied
  complex y1(-2, -30);
  complex y(y1);
  ASSERT(-2 == y.re() && -30 == y.im());
  
  // TEST 4: Check if -2-30j can be copied using '='
  complex y2 = y1;
  ASSERT(-2 == y2.re() && -30 == y2.im());

  SUCCEED;
}
