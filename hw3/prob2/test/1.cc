#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS
  // This file tests all constructors by building a complex number
  // with each and then testing that the complex number is correct 
  // using the getters.

  // TEST 1: Check if 3.25+4.16j can be initialized
  complex x(3.25, 4.16);
  ASSERT(3.25 == x.re() && 4.16 == x.im());

  // TEST 2: Check if -2.023-30.001j can be initialized
  complex y(-2.023, -30.001);
  ASSERT(-2.023 == y.re() && -30.001 == y.im());
  
  SUCCEED;
}
