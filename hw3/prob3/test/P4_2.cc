#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

int main ( int argc, char * argv[] ) {
  // DFT TRANSFORM MATRIX TESTS
  // This file tests the transform_matrix() method to create a 
  // nxn DFT matrix for the transform

  // Test 1: Check DFT transform matrix can be computed
  // The cached matrix should be stored in the map dft_matrices
  // with key = 1
  DFT d(4);
  d.transform_matrix();
  ASSERT((complex)1 == DFT::dft_matrices[1].get(0, 0));
  ASSERT((complex)1 == DFT::dft_matrices[1].get(2, 0));
  ASSERT((complex)1 == DFT::dft_matrices[1].get(0, 3));
  std::cout << DFT::dft_matrices[1].get(3, 3);

  SUCCEED;
}
