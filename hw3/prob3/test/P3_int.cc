#include <iostream>
#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE INT
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 3x3 matrix with entries of type int can be created
  // Check matrix dimensions are correct
  matrix<int> A(2, 2);
  ASSERT(2 == A.rows());
  ASSERT(2 == A.columns());
  ASSERT(A.in_range(1, 1));
  ASSERT(!A.in_range(2, 2));

  // Test set 2: Matrix entry setter/getter tests
  // Check entries in matrix can be set and retrieved
  A.set(0, 0, 1); A.set(0, 1, 2);
  A.set(1, 0, 3); A.set(1, 1, 4);
  ASSERT(1 == A.get(0, 0));
  ASSERT(2 == A.get(0, 1));
  ASSERT(3 == A.get(1, 0));
  ASSERT(4 == A.get(1, 1));

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<int> B = A;
  ASSERT(B == A);

  // Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted,
  // and scaled using the overloaded operators
  // C = [2 4
  //      6 8]
  matrix<int> C = A + B;
  ASSERT(2 == C.get(0, 0));
  ASSERT(4 == C.get(0, 1));
  ASSERT(6 == C.get(1, 0));
  ASSERT(8 == C.get(1, 1));
  // D = [1 2
  //      3 4]
  matrix<int> D = C - A;
  ASSERT(D == B);
  // E = [14 20
  //      30 44]
  matrix<int> E = A * C;
  ASSERT(14 == E.get(0, 0));
  ASSERT(20 == E.get(0, 1));
  ASSERT(30 == E.get(1, 0));
  ASSERT(44 == E.get(1, 1));
  // F = 2 * A = [2 4
  //              6 8]
  matrix<int> F = A.scale(2);
  ASSERT(F == C);

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  ASSERT(D == B);
  ASSERT(D != C);
  ASSERT(C > A);
  ASSERT(B < F);
  ASSERT(D <= A);
  ASSERT(B >= A);

  SUCCEED;
}
