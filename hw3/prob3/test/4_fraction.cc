#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE FRACTION
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 3x3 matrix with entries of type fraction can be created
  // Check matrix dimensions are correct
  matrix<fraction> A(2, 2);
  ASSERT(2 == A.rows());
  ASSERT(2 == A.columns());
  ASSERT(A.in_range(1, 1));
  ASSERT(!A.in_range(2, 2));

  // Test set 2: Matrix entry setter/getter tests
  // Check entries in matrix can be set and retrieved
  fraction A1(1, 3); fraction A2(-2, 3);
  fraction A3(3, 4); fraction A4(-9, 5);
  A.set(0, 0, A1); A.set(0, 1, A2);
  A.set(1, 0, A3); A.set(1, 1, A4);
  ASSERT(A1 == A.get(0, 0));
  ASSERT(A2 == A.get(0, 1));
  ASSERT(A3 == A.get(1, 0));
  ASSERT(A4 == A.get(1, 1));

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<fraction> B = A;
  ASSERT(B == A);

  SUCCEED;
}
