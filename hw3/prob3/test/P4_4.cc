#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT UNITARY MATRIX TESTS
  // This file tests the unitary_matrix() method to create a 
  // nxn DFT unitary matrix for the transform

  // Test 1: Check DFT inverse matrix can be computed
  DFT d(4);
  d.inverse_matrix();
  ASSERT(TOLERANCE > DFT::dft_matrices[3].get(0, 0).im() - 0.125);
  ASSERT(TOLERANCE > DFT::dft_matrices[3].get(2, 0).im() - 0.125);
  ASSERT(TOLERANCE > DFT::dft_matrices[3].get(0, 3).im() - 0.125);
  std::cout << DFT::dft_matrices[3].get(3, 3);

  SUCCEED;
}
