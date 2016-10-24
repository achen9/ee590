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

  /*//Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted,
  // and scaled using the overloaded operators
  // C = [2 4
  //      6 8]
  matrix<bool> C = A + B;
  ASSERT(2 == C.get(0, 0));
  ASSERT(4 == C.get(0, 1));
  ASSERT(6 == C.get(1, 0));
  ASSERT(8 == C.get(1, 1));
  // D = [1 2
  //      3 4]
  matrix<bool> D = C - A;
  ASSERT(D == B);
  // E = [14 20
  //      30 44]
  matrix<bool> E = A * C;
  ASSERT(14 == E.get(0, 0));
  ASSERT(20 == E.get(0, 1));
  ASSERT(30 == E.get(1, 0));
  ASSERT(44 == E.get(1, 1));
  // F = 2 * A = [2 4
  //              6 8]
  matrix<bool> F = A.scale(2);
  ASSERT(F == C);
  */

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  /*ASSERT(D == B);
  ASSERT(D != C);
  ASSERT(C > A);
  ASSERT(B < F);
  ASSERT(D <= A);
  ASSERT(B >= A);
  */

  // Test set 7: Named constructor tests
  // Test the named constructors identity, and ones
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
    for (int j = 0; j < size; j++) {
      ASSERT(true == O.get(i, j));
    }
  }

  SUCCEED;
}
