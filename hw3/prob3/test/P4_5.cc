#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT TESTS
  // This file tests the dft() method to compute
  // the DFT of an input vector

  // Test 1: Check DFT can be computed
  DFT d(4);
  matrix<complex> input(4, 1);
  input.set(0, 0, (complex)1);
  input.set(1, 0, (complex)1);
  input.set(2, 0, (complex)1);
  input.set(3, 0, (complex)1);
  matrix<complex> output = d.dft(input);
  std::cout << std::endl << output;

  DFT e(4);
  matrix<complex> bad_input(5, 1);
  try {
    matrix<complex> bad_output = e.dft(bad_input);
  } catch (DFT_exception e) {
    SUCCEED;
  }
  FAIL;
}
