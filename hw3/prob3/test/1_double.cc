#include <iostream>
#include "test.hh"
#include "matrix.hh"

#define TOLERANCE 0.0001

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE DOUBLE
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 3x3 matrix with entries of type double can be created
  // Check matrix dimensions are correct
  matrix<double> A(2,2);
  ASSERT(2 == A.rows());
  ASSERT(2 == A.columns());
  ASSERT(A.in_range(1, 1));
  ASSERT(!A.in_range(2, 2));

  // Test set 2: Matrix entry setter/getter tests
  // Check entries in matrix can be set and retrieved
  A.set(0, 0, 1.0); A.set(0, 1, 2.0);
  A.set(1, 0, 3.0); A.set(1, 1, 4.0);
  ASSERT(TOLERANCE > A.get(0, 0) - 1.0);
  ASSERT(TOLERANCE > A.get(0, 1) - 2.0);
  ASSERT(TOLERANCE > A.get(1, 0) - 3.0);
  ASSERT(TOLERANCE > A.get(1, 1) - 4.0);

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<double> B = A;
  ASSERT(B == A);

  std::cout << "  ";
  SUCCEED;
}
