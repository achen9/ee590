#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT UNITARY MATRIX TESTS
  // This file tests the unitary_matrix() method to create a 
  // nxn DFT unitary matrix for the transform

  // Test 1: Check DFT unitary matrix can be computed
  DFT d(4);
  complex d_elem = 1;
  for (int i = 0; i < 4; i++) {
    d.set(0, d_elem);
  }
  d.unitary_matrix();
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(0, 0));
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(2, 0));
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(0, 3));
  std::cout << DFT::dft_matrices[2].get(3, 3);

  SUCCEED;
}
