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
#include <map>
#include "complex.hh"
#include "DFT.hh"

#define PI 3.14159

std::map<int, matrix<complex>> DFT::dft_matrices;
std::map<int, matrix<complex>>::iterator DFT::it;

DFT::DFT(int n) : num_pts(n) {
  if (n <= 0) {
    throw DFT_exception("Negative or 0 number of points in sequence.");
  }
  points = new complex[n];
}
DFT::~DFT() {
  delete []points;
}
complex DFT::get(int n) const {
  if (num_pts < n || 0 > n) {
    throw DFT_exception("Attempted to access point in sequence that is out of range.");
  }
  complex elem = points[n];
  return elem;
}
void DFT::set(int n, complex c) {
  if (num_pts < n || 0 > n) {
    throw DFT_exception("Attempted to set point in sequence that is out of range.");
  }
  points[n] = c;
}
matrix<complex> DFT::transform_matrix(void) {
  it = dft_matrices.find(1);
  if (it == dft_matrices.end()) {
    complex exponent(0, -2 * PI / num_pts);
    complex w = exponent.exp();
    matrix<complex> m(num_pts);
    for (int i = 0; i < m.rows(); i++) {
      for (int j = 0; j < m.columns(); j++) {
        m.set(i, j, w.pow(i*j));
      }
    }
    dft_matrices[1] = m;
  }
  return dft_matrices[1];
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
