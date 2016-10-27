#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define N_PTS 4

int main ( int argc, char * argv[] ) {
  // DFT AND INVERSE DFT TESTS
  // This file tests the dft() and dft_inv() methods 
  // to see if a a dft applied to an input, then an inverse
  // dft applied to that output yields a sequence that is 
  // close to the original input

  // Test 1: Check the original input can be recovered
  // after a dft and dft-inverse is applied
  DFT d(N_PTS);
  matrix<complex> input(N_PTS, 1);
  for (int i = 0; i < N_PTS; i++) {
    complex rand = complex::random(-5.0, 5.0);
    input.set(i, 0, rand);
  }
  matrix<complex> output = d.dft(input);
  matrix<complex> input_check = d.dft_inv(output);
  for (int i = 0; i < N_PTS; i++) {
    // The complex class has an overloaded '==' operator
    // with a tolerance of 0.00001
    ASSERT(input.get(i, 0) == input_check.get(i, 0));
  }
  SUCCEED;
}
