#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

int main ( int argc, char * argv[] ) {
  // DFT INVERSE DFT  TESTS
  // This file tests the dft_inv() method to compute 
  // the inverse DFT of an input vector

  // Test 1: Check DFT inverse can be computed
  DFT d(4);
  matrix<complex> input(4, 1);
  for (int i = 0; i < 4; i++) {
    input.set(i, 0, complex::random(-5.0, 5.0));
  }
  matrix<complex> output = d.dft_inv(input);
  std::cout << std::endl << output;

  // Test 2: Check if mismatch between number of points in 
  // input vector and DFT number of points causes error
  DFT e(4);
  matrix<complex> bad_input(5, 1);
  try {
    matrix<complex> bad_output = e.dft_inv(bad_input);
  } catch (DFT_exception e) {
    SUCCEED;
  }
  FAIL;
}
