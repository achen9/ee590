#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS
  // This file tests all constructors by building a fraction with each and then
  // testing that the fraction is correct using the getters.

  // TEST 1: Check if 3+4j can be initialized
  complex x(3, 4);
  ASSERT(3 == x.re() && 4 == x.im());

  // TEST 2: Check if -2-30j can be initialized
  complex y(-2, -30);
  ASSERT(-2 == y.re() && -30 == y.im());
  
  SUCCEED;
}
