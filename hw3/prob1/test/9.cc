#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // PRINTING FRACTIONS TESTS
  // This file tests the '<<' operator overload

  // TEST 1: Print 2/3
  fraction x(2, 3);
  std::cout << " : " << x << ", ";

  // TEST 2: Print -2/3
  std::cout << -x << ", ";

  // TEST 3: Print -32/-3
  fraction y(-32, -3);
  std::cout << y << ", ";
  
  // TEST 4: Print 582/-648
  fraction z(582, -648);
  std::cout << z;
  
  SUCCEED;
}
