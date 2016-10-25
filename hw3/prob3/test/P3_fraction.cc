#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE FRACTION
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 2x2 matrix with entries of type fraction can be created
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
  ASSERT(!(C > A));
  ASSERT(!(B < F));
  ASSERT(D <= A);
  ASSERT(B >= A);

  // Test set 6: Matrix operations tests
  // Check matrix minor, determinant, and inverse methods
  matrix<fraction> G(3,3);
  G.set(0, 0, 5); G.set(0, 1, 3); G.set(0, 2, -4);
  G.set(1, 0, 2); G.set(1, 1, 0); G.set(1, 2, -2);
  G.set(2, 0, 2); G.set(2, 1, 5); G.set(2, 2, -1);
  matrix<fraction> H = G.m_minor(0, 0);
  ASSERT((fraction)0 == H.get(0, 0));
  ASSERT((fraction)-2 == H.get(0, 1));
  ASSERT((fraction)5 == H.get(1, 0));
  ASSERT((fraction)-1 == H.get(1, 1));
  ASSERT((fraction)4 == G.det());
  // inverse(G) = [2.5  -4.25 -1.5
  //               -0.5 0.75  0.5
  //               2.5  -4.75 -1.5]
  matrix<fraction> K = G.inverse();
  fraction G1(5, 2); fraction G2(-17, 4); fraction G3(-3, 2);
  fraction G4(-1, 2); fraction G5(3, 4); fraction G6(1, 2);
  fraction G7(5, 2); fraction G8(-19, 4); fraction G9(-3, 2);
  ASSERT(G1 == K.get(0, 0));
  ASSERT(G2 == K.get(0, 1));
  ASSERT(G3 == K.get(0, 2));
  ASSERT(G4 == K.get(1, 0));
  ASSERT(G5 == K.get(1, 1));
  ASSERT(G6 == K.get(1, 2));
  ASSERT(G7 == K.get(2, 0));
  ASSERT(G8 == K.get(2, 1));
  ASSERT(G9 == K.get(2, 2));

  // Test set 7: Named constructor tests
  // Test the named constructors identity, and ones
  int size = 4;
  matrix<fraction> I = matrix<fraction>::identity(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        ASSERT((fraction)1 == I.get(i, j));
      } else {
        ASSERT((fraction)0 == I.get(i, j));
      }
    }
  }
  matrix<fraction> O = matrix<fraction>::ones(size, size - 1);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      ASSERT((fraction)1 == O.get(i, j));
    }
  }

  std::cout << std::endl << F;

  SUCCEED;
}
