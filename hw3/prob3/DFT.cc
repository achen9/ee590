/* NAME
 *  DFT.cc
 *
 * DESCRIPTION
 *  Defines methods for DFT class
 *
 * PARAMETERS
 *  See specific method
 *
 * RETURN
 *  See specific method
 * 
 * EXAMPLE
 *  See specific method
 *
 * NOTES
 *  Make sure the makefile is available to compile the code
 *
 * Alex Z. Chen - 10/23/2016
 * alexac9@uw.edu
 */
#include <iostream>
#include <math.h>
#include "complex.hh"
#include "DFT.hh"

DFT::DFT(int n) {
  if (n <= 0) {
    throw DFT_exception("Negative or 0 number of points in sequence.");
  }
  numPoints = n;
  points = new complex[n];
}
DFT::~DFT() {
  delete []points;
}
complex DFT::get(int n) const {
  if (numPoints < n || 0 > n) {
    throw DFT_exception("Attempted to access point in sequence that is out of range.");
  }
  complex elem = points[n];
  return elem;
}
/*
DFT &DFT::operator=(const complex &other) {
  if (this != &other) {
    real = other.re();
    imaginary = other.im();
  }
  return *this;
}
std::ostream& operator<<(std::ostream& os, const complex &c) {
  os << c.re();
  if (0 < c.im()) {
    os << '+';
  } 
  os << c.im() << 'j';
  return os;
}
*/
