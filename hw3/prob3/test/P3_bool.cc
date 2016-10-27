#include <iostream>
#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE BOOL
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 2x2 matrix with entries of type bool can be created
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

  //Test set 4: Arithmetic operations tests - N/A to boolean types

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  matrix<bool> C(2, 2);
  C.set(0, 0, false); C.set(0, 1, true);
  C.set(1, 0, false); C.set(1, 1, true);
  ASSERT(A == B);
  ASSERT(A != C);
  ASSERT(B <= A);
  ASSERT(B >= A);

  // Test set 6: Matrix operations tests - N/A to boolean types

  // Test set 7: Named constructor tests
  // Test the named constructors identity and ones
  int size = 4;
  matrix<bool> I = matrix<bool>::identity(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        ASSERT(true == I.get(i, j));
      } else {
        ASSERT(false == I.get(i, j));
      }
    }
  }
  matrix<bool> O = matrix<bool>::ones(size, size - 1);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      ASSERT(true == O.get(i, j));
    }
  }

  // Test set 8: Interface with ostreams tests
  // Test the printing of the matrix to std output
  std::cout << std::boolalpha;
  std::cout << std::endl << I;

  SUCCEED;
}
