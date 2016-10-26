#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT UNITARY MATRIX TESTS
  // This file tests the transform_matrix() method to create a 
  // nxn DFT matrix for the transform

  // Test 1: Check DFT transform matrix can be computed
  DFT d(4);
  d.transform_matrix();
  ASSERT((complex)1 == DFT::dft_matrices[1].get(0, 0));
  ASSERT((complex)1 == DFT::dft_matrices[1].get(2, 0));
  ASSERT((complex)1 == DFT::dft_matrices[1].get(0, 3));
  std::cout << DFT::dft_matrices[1].get(3, 3);

  SUCCEED;
}
