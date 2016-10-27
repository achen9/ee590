#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001
#define N_PTS 6

int main ( int argc, char * argv[] ) {
  // UNITARY MATRIX TESTS
  // This file tests if the unitary matrix raised
  // to the power of 4 is approximately the identity
  // matrix

  DFT d(N_PTS);
  matrix<complex> u = d.unitary_matrix();
  matrix<complex> u4 = u * u * u * u;
  matrix<complex> I = matrix<complex>::identity(N_PTS);
  ASSERT(u4 == I)
  SUCCEED;
}
