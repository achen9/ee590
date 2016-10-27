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
  // Check a 2x2 matrix with entries of type complex can be created
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
  ASSERT(TOLERANCE > std::abs(A.get(0, 0).re() - 1.2) && TOLERANCE > std::abs(A.get(0, 0).im() - 3.1));
  ASSERT(TOLERANCE > std::abs(A.get(0, 1).re() + 2.4) && TOLERANCE > std::abs(A.get(0, 1).im() - 3.9));
  ASSERT(TOLERANCE > std::abs(A.get(1, 0).re() - 3.6) && TOLERANCE > std::abs(A.get(1, 0).im() - 4.0));
  ASSERT(TOLERANCE > std::abs(A.get(1, 1).re() + 9.7) && TOLERANCE > std::abs(A.get(1, 1).im() - 5.4));

  // Test set 3: Copy constructor tests
  // Check matrix A can be copied using the '=' overloaded operator
  matrix<complex> B = A;
  ASSERT(B == A);

  // Test set 4: Arithmetic operations tests
  // Check if matrices can be added, multiplied, subtracted,
  // and scaled using the overloaded operators
  // C = [2.4+6.2j -4.8+7.8j
  //      7.2+8j   -19.4+10.8j]
  matrix<complex> C = A + B;
  complex C1(2.4, 6.2); complex C2(-4.8, 7.8);
  complex C3(7.2, 8.0); complex C4(-19.4, 10.8);
  ASSERT(TOLERANCE > std::abs(C.get(0, 0).re() - 2.4) && TOLERANCE > std::abs(C.get(0, 0).im() - 6.2));
  ASSERT(TOLERANCE > std::abs(C.get(0, 1).re() + 4.8) && TOLERANCE > std::abs(C.get(0, 1).im() - 7.8));
  ASSERT(TOLERANCE > std::abs(C.get(1, 0).re() - 7.2) && TOLERANCE > std::abs(C.get(1, 0).im() - 8.0));
  ASSERT(TOLERANCE > std::abs(C.get(1, 1).re() + 19.4) && TOLERANCE > std::abs(C.get(1, 1).im() - 10.8));
  // D = [1.2+3.1j -2.4+3.9j
  //      3.6+4j   -9.7+5.4j]
  matrix<complex> D = C - A;
  ASSERT(D == B);
  // E = [-64.82+23.76j -25.5-107.1j
  //      -129.2-6.8j   81.38-200.64j]
  matrix<complex> E = A * C;
  ASSERT(TOLERANCE > std::abs(E.get(0, 0).re() + 64.82) && TOLERANCE > std::abs(E.get(0, 0).im() - 23.76));
  ASSERT(TOLERANCE > std::abs(E.get(0, 1).re() + 25.5) && TOLERANCE > std::abs(E.get(0, 1).im() + 107.1));
  ASSERT(TOLERANCE > std::abs(E.get(1, 0).re() + 129.2) && TOLERANCE > std::abs(E.get(1, 0).im() + 6.8));
  ASSERT(TOLERANCE > std::abs(E.get(1, 1).re() - 81.38) && TOLERANCE > std::abs(E.get(1, 1).im() + 200.64));
  // F = 2 * A = [2.4+6.2j -4.8+7.8j
  //              7.2+8j   -19.4+10.8j]
  complex S = 2;
  matrix<complex> F = A.scale(S);
  ASSERT(F == C);

  // Test Set 5: Relational operation tests
  // Check if matrices can be compared using the overloaded
  // relational operators: '==','!=','>','<','>=','<='
  // Note: '>','<','>=','<=' do not make sense for comparing
  // complex numbers
  ASSERT(D == B);
  ASSERT(D != C);

  // Test set 6: Matrix operations tests
  // Check matrix minor, determinant, and inverse methods
  matrix<complex> G(3,3);
  G.set(0, 0, 5); G.set(0, 1, 3); G.set(0, 2, -4);
  G.set(1, 0, 2); G.set(1, 1, 0); G.set(1, 2, -2);
  G.set(2, 0, 2); G.set(2, 1, 5); G.set(2, 2, -1);
  matrix<complex> H = G.m_minor(0, 0);
  ASSERT(TOLERANCE > H.get(0, 0).re() - 0.0 && TOLERANCE > H.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > H.get(0, 1).re() + 2.0 && TOLERANCE > H.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > H.get(1, 0).re() - 5.0 && TOLERANCE > H.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > H.get(1, 1).re() + 1.0 && TOLERANCE > H.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > G.det().re() - 4.0 && TOLERANCE > G.det().im() - 0.0);
  // inverse(G) = [2.5  -4.25 -1.5
  //               -0.5 0.75  0.5
  //               2.5  -4.75 -1.5]
  matrix<complex> K = G.inverse();
  ASSERT(TOLERANCE > K.get(0, 0).re() - 2.5 && TOLERANCE > K.get(0,0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(0, 1).re() + 4.25 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(0, 2).re() + 1.5 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(1, 0).re() + 0.5 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(1, 1).re() - 0.75 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(1, 2).re() - 0.5 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(2, 0).re() - 2.5 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(2, 1).re() + 4.75 && TOLERANCE > K.get(0, 0).im() - 0.0);
  ASSERT(TOLERANCE > K.get(2, 2).re() + 1.5 && TOLERANCE > K.get(0, 0).im() - 0.0);

  // Test set 7: Named constructor tests
  // Test the named constructors identity, and ones
  int size = 4;
  matrix<complex> I = matrix<complex>::identity(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        ASSERT(TOLERANCE > I.get(i, j).re() - 1.0 && TOLERANCE > I.get(i, j).im() - 0.0);
      } else {
        ASSERT(TOLERANCE > I.get(i, j).re() - 0.0 && TOLERANCE > I.get(i, j).im() - 0.0);
      }
    }
  }
  matrix<complex> O = matrix<complex>::ones(size, size - 1);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      ASSERT(TOLERANCE > O.get(i, j).re() - 1.0 && TOLERANCE > I.get(i, j).im() - 0.0);
    }
  }

  // Test set 8: Interface with ostreams tests
  // Test the printing of the matrix to std output
  std::cout << std::endl << F;

  SUCCEED;
}
