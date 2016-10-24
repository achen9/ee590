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

  // Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted, 
  // and scaled using the overloaded operators
  // C = [2/3 -4/3
  //      3/2 -18/5]
  matrix<fraction> C = A + B;
  fraction C1(2, 3); fraction C2(-4, 3);
  fraction C3(3, 2); fraction C4(-18, 5);
  ASSERT(C1 == C.get(0, 0));
  ASSERT(C2 == C.get(0, 1));
  ASSERT(C3 == C.get(1, 0));
  ASSERT(C4 == C.get(1, 1));
  // D = [1/3 -2/3
  //      3/4 -9/5]
  matrix<fraction> D = C - A;
  ASSERT(D == B);
  // E = [-7/9 88/45
  //      -11/5 137/25]
  matrix<fraction> E = A * C;
  fraction E1(-7, 9); fraction E2(88, 45);
  fraction E3(-11, 5); fraction E4(137, 25);
  ASSERT(E1 == E.get(0, 0));
  ASSERT(E2 == E.get(0, 1));
  ASSERT(E3 == E.get(1, 0));
  ASSERT(E4 == E.get(1, 1));
  // F = 2 * A = [2/3 -4/3
  //              3/2 -18/5]
  fraction S = 2;
  matrix<fraction> F = A.scale(S);
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
