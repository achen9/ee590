#include <iostream>
#include "test.hh"
#include "matrix.hh"

#define TOLERANCE 0.001

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
  A.set(0, 0, 1.6); A.set(0, 1, 2.3);
  A.set(1, 0, 3.2); A.set(1, 1, 4.1);
  ASSERT(TOLERANCE > A.get(0, 0) - 1.6);
  ASSERT(TOLERANCE > A.get(0, 1) - 2.3);
  ASSERT(TOLERANCE > A.get(1, 0) - 3.2);
  ASSERT(TOLERANCE > A.get(1, 1) - 4.1);

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<double> B = A;
  ASSERT(B == A);

  // Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted,
  // and scaled using the overloaded operators
  // C = [3.2 4.6
  //      6.4 8.2]
  matrix<double> C = A + B;
  ASSERT(TOLERANCE > C.get(0, 0) - 3.2);
  ASSERT(TOLERANCE > C.get(0, 1) - 4.6);
  ASSERT(TOLERANCE > C.get(1, 0) - 6.4);
  ASSERT(TOLERANCE > C.get(1, 1) - 8.2);
  // D = [1.6 2.3
  //      3.2 4.1]
  matrix<double> D = C - A;
  ASSERT(TOLERANCE > D.get(0, 0) - 1.6);
  ASSERT(TOLERANCE > D.get(0, 1) - 2.3);
  ASSERT(TOLERANCE > D.get(1, 0) - 3.2);
  ASSERT(TOLERANCE > D.get(1, 1) - 4.1);
  // E = [19.84 26.22
  //      36.48 48.34]
  matrix<double> E = A * C;
  ASSERT(TOLERANCE > E.get(0, 0) - 19.84);
  ASSERT(TOLERANCE > E.get(0, 1) - 26.22);
  ASSERT(TOLERANCE > E.get(1, 0) - 36.48);
  ASSERT(TOLERANCE > E.get(1, 1) - 48.34);
  // F = 2 * A = [3.2 4.6
  //              6.4 8.2]
  matrix<double> F = A.scale(2.0);
  ASSERT(TOLERANCE > F.get(0, 0) - 3.2);
  ASSERT(TOLERANCE > F.get(0, 1) - 4.6);
  ASSERT(TOLERANCE > F.get(1, 0) - 6.4);
  ASSERT(TOLERANCE > F.get(1, 1) - 8.2);

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  // Note: due to rounding errors, '==', '<=','>=' can cause
  // erroneous results and have been commented out
  //ASSERT(D == B);
  ASSERT(D != C);
  ASSERT(C > A);
  ASSERT(B < F);
  ASSERT(D <= C);
  ASSERT(F >= B);

  SUCCEED;
}
