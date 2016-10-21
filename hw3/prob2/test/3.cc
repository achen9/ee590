#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // OVERLOAD '=' TESTS
  // This file tests the overloaded '=' operator for real numbers

  // TEST 1: Check if 3+0j can be created
  complex x = 3.0;
  ASSERT(3.0 == x.re() && 0.0 == x.im());

  // TEST 2: Check if -3.44+0j can be created
  complex y = -3.44;
  ASSERT(-3.44 == y.re() && 0.0 == y.im());

  // TEST 3: Check if -0.00+0j can be created
  complex z = 0.00;
  ASSERT(0.0 == z.re() && 0.0 == z.im());
  
  SUCCEED;
}
