#include <iostream>
#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {
  // MATRIX TEMPLATE TESTS FOR TYPE INT
  // This file tests all methods for a matrix library template 
  // implemented in matrix.impl.hh

  // Test set 1: Constructor & matrix dimension getter tests
  // Check a 2x2 matrix with entries of type int can be created
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

  // Test set 6: Matrix operations tests
  // Check matrix minor, determinant, and inverse methods
  matrix<int> G(3,3);
  G.set(0, 0, 5); G.set(0, 1, 3); G.set(0, 2, -4);
  G.set(1, 0, 2); G.set(1, 1, 0); G.set(1, 2, -2);
  G.set(2, 0, 2); G.set(2, 1, 5); G.set(2, 2, -1);
  matrix<int> H = G.m_minor(0, 0);
  ASSERT(0 == H.get(0, 0));
  ASSERT(-2 == H.get(0, 1));
  ASSERT(5 == H.get(1, 0));
  ASSERT(-1 == H.get(1, 1));
  ASSERT(4 == G.det());

  // Test set 7: Named constructor tests
  // Test the named constructors identity, and ones
  int size = 4;
  matrix<int> I = matrix<int>::identity(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        ASSERT(1 == I.get(i, j));
      } else {
        ASSERT(0 == I.get(i, j));
      }
    }
  }
  matrix<int> O = matrix<int>::ones(size, size-1);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      ASSERT(1 == O.get(i, j));
    }
  }

  std::cout << std::endl << F ;
  
  SUCCEED;
}
