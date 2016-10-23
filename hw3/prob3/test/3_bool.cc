#include <iostream>
#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE BOOL
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 3x3 matrix with entries of type bool can be created
  // Check matrix dimensions are correct
  matrix<bool> A(2, 2);
  ASSERT(2 == A.rows());
  ASSERT(2 == A.columns());
  ASSERT(A.in_range(1, 1));
  ASSERT(!A.in_range(2, 2));

  // Test set 2: Matrix entry setter/getter tests
  // Check entries in matrix can be set and retrieved
  A.set(0, 0, true); A.set(0, 1, false);
  A.set(1, 0, false); A.set(1, 1, true);
  ASSERT(true == A.get(0, 0));
  ASSERT(false == A.get(0, 1));
  ASSERT(false == A.get(1, 0));
  ASSERT(true == A.get(1, 1));

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<bool> B = A;
  ASSERT(B == A);

  std::cout << "    ";
  SUCCEED;
}
