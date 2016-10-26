#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT INVERSE DFT  TESTS
  // This file tests the dft_inv() method to compute 
  // the inverse DFT of an input vector

  // Test 1: Check DFT inverse can be computed
  DFT d(4);
  matrix<complex> input(4, 1);
  input.set(0, 0, (complex)1);
  input.set(1, 0, (complex)1);
  input.set(2, 0, (complex)1);
  input.set(3, 0, (complex)1);
  matrix<complex> output = d.dft_inv(input);
  std::cout << std::endl << output;

  DFT e(4);
  matrix<complex> bad_input(5, 1);
  try {
    matrix<complex> bad_output = e.dft_inv(bad_input);
  } catch (DFT_exception e) {
    SUCCEED;
  }
  FAIL;
}
