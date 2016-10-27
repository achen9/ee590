#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

int main ( int argc, char * argv[] ) {
  // DFT TESTS
  // This file tests the dft() method to compute
  // the DFT of an input vector

  // Test 1: Check DFT can be computed
  DFT d(4);
  matrix<complex> input(4, 1);
  for (int i = 0; i < 4; i++) {
    input.set(i, 0, complex::random(-5.0, 5.0));
  }
  matrix<complex> output = d.dft(input);
  std::cout << std::endl << output;

  // Test 2: Check if mismatch between number of points in 
  // input vector and DFT number of points causes error
  DFT e(4);
  matrix<complex> bad_input(5, 1);
  try {
    matrix<complex> bad_output = e.dft(bad_input);
  } catch (DFT_exception e) {
    SUCCEED;
  }
  FAIL;
}
