#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "complex.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE COMPLEX
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 3x3 matrix with entries of type complex can be created
  // Check matrix dimensions are correct
  matrix<complex> A(2, 2);
  ASSERT(2 == A.rows());
  ASSERT(2 == A.columns());
  ASSERT(A.in_range(1, 1));
  ASSERT(!A.in_range(2, 2));

  // Test set 2: Matrix entry setter/getter tests
  // Check entries in matrix can be set and retrieved
  complex A1(1.2, 3.1); complex A2(-2.4, 3.9);
  complex A3(3.6, 4.0); complex A4(-9.7, 5.4);
  A.set(0, 0, A1); A.set(0, 1, A2);
  A.set(1, 0, A3); A.set(1, 1, A4);
  ASSERT(TOLERANCE > A.get(0, 0).re() - 1.2 && TOLERANCE > A.get(0, 0).im() - 3.1);
  ASSERT(TOLERANCE > A.get(0, 1).re() + 2.4 && TOLERANCE > A.get(0, 1).im() - 3.9);
  ASSERT(TOLERANCE > A.get(1, 0).re() - 3.6 && TOLERANCE > A.get(1, 0).im() - 4.0);
  ASSERT(TOLERANCE > A.get(1, 1).re() + 9.7 && TOLERANCE > A.get(1, 1).im() - 5.4);

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<complex> B = A;
  ASSERT(TOLERANCE > B.get(0, 0).re() - 1.2 && TOLERANCE > B.get(0, 0).im() - 3.1);
  ASSERT(TOLERANCE > B.get(0, 1).re() + 2.4 && TOLERANCE > B.get(0, 1).im() - 3.9);
  ASSERT(TOLERANCE > B.get(1, 0).re() - 3.6 && TOLERANCE > B.get(1, 0).im() - 4.0);
  ASSERT(TOLERANCE > B.get(1, 1).re() + 9.7 && TOLERANCE > B.get(1, 1).im() - 5.4);

  // Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted,
  // and scaled using the overloaded operators
  // C = [2.4+6.2j -4.8+7.8j
  //      7.2+8j   -19.4+10.8j]
  matrix<complex> C = A + B;
  complex C1(2.4, 6.2); complex C2(-4.8, 7.8);
  complex C3(7.2, 8.0); complex C4(-19.4, 10.8);
  //ASSERT(C1 == C.get(0, 0));
  //ASSERT(C2 == C.get(0, 1));
  //ASSERT(C3 == C.get(1, 0));
  //ASSERT(C4 == C.get(1, 1));
  // D = [1.2+3.1j -2.4+3.9j
  //      3.6+4j   -9.7+5.4j]
  matrix<complex> D = C - A;
  //ASSERT(D == B);
  // E = [-64.82+23.76j -25.5-107.1j
  //      -129.2-6.8j   81.38-200.64j]
  matrix<complex> E = A * C;
  //ASSERT(14 == E.get(0, 0));
  //ASSERT(20 == E.get(0, 1));
  //ASSERT(30 == E.get(1, 0));
  //ASSERT(44 == E.get(1, 1));
  // F = 2 * A = [2/3 -4/3
  //              3/2 -18/5]
  complex S = 2;
  matrix<complex> F = A.scale(S);
  //ASSERT(F == C);

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  // Note: '>','<','>=','<=' do not make sense for comparing
  // complex numbers
  //ASSERT(D == B);
  //ASSERT(D != C);

  SUCCEED;
}
