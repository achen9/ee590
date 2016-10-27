#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

int main ( int argc, char * argv[] ) {
  // DFT UNITARY MATRIX TESTS
  // This file tests the unitary_matrix() method to create a 
  // nxn DFT unitary matrix for the transform

  // Test 1: Check DFT unitary matrix can be computed
  // The cached matrix should be stored in the map dft_matrices
  // with key = 2
  DFT d(4);
  d.unitary_matrix();
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(0, 0));
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(2, 0));
  ASSERT((complex)0.5 == DFT::dft_matrices[2].get(0, 3));
  std::cout << DFT::dft_matrices[2].get(3, 3);

  SUCCEED;
}
