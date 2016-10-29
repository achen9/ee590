#include <iostream>
#include "json.hh"
#include "test.hh"

int main ( int argc, char * argv[] ) {
  // ARRAY SIZE ADJUSTMENT TESTS
  // This file tests the array size adjustment in the
  // set() method if one attempts to set an index that
  // is larger than the current array size

  // Test 1: Check array length is increased if an index
  // greater than max array length is set
  Array a;
  Number n0(0);
  Number n9(9);
  Number n21(21);

  a.set(0, n0);
  a.set(9, n9);
  std::cout << std::endl << "Array max length is: " << a.get_max() << std::endl;
  ASSERT(10 == a.length());
  std::cout << "Setting 21st element..." << std::endl;
  a.set(21, n21);
  std::cout << "New array max is: " << a.get_max() << std::endl;
  ASSERT(22 == a.length());

  SUCCEED;
}
