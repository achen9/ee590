#include <iostream>
#include "test.hh"
#include "matrix.hh"
#include "DFT.hh"

#define TOLERANCE 0.001

int main ( int argc, char * argv[] ) {
  // DFT CONSTRUCTOR TESTS
  // This file tests the constructor method for the DFT class

  // Test 1: Check a DFT class can be constructed
  DFT d(5);
  for (int i = 0; i < 5; i++) {
    ASSERT(TOLERANCE > d.get(i).re() - 0.0 && TOLERANCE > d.get(i).im() - 0.0);
  }
  
  // Test 2: Check if negative number of points is entered -> error
  try {
    DFT e(-4);
  } catch (DFT_exception e) {
    SUCCEED;
  }
  FAIL;
}
