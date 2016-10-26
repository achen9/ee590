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
}
matrix<complex> DFT::transform_matrix(void) {
  it = dft_matrices.find(1);
  if (it == dft_matrices.end()) { // map is empty
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
matrix<complex> DFT::unitary_matrix(void) {
  it = dft_matrices.find(2);
  if (it == dft_matrices.end()) { // map does not contain unitary matrix
    matrix<complex> m = transform_matrix();
    matrix<complex> u = m.scale((complex)(1.0 / std::sqrt(num_pts)));
    dft_matrices[2] = u;
  }
  return dft_matrices[2];
}
matrix<complex> DFT::inverse_matrix(void) {
  it = dft_matrices.find(3);
  if (it == dft_matrices.end()) { // map does not contain inverse matrix
    matrix<complex> u = unitary_matrix();
    matrix<complex> inv = conjugate_transpose(u);
    inv = inv.scale((complex)(1.0 / num_pts));
    dft_matrices[3] = inv;
  }
  return dft_matrices[3];
}
matrix<complex> DFT::conjugate_transpose(const matrix<complex> &m) const {
  matrix<complex> t = m.transpose();
  matrix<complex> ct(t.rows(), t.columns());
  for (int i = 0; i < ct.rows(); i++) {
    for (int j = 0; j < ct.columns(); j++) {
      ct.set(i, j, t.get(i, j).conjugate());
    }
  }
  return ct;
}
matrix<complex> DFT::dft(const matrix<complex> &m) {
  if (num_pts != m.rows() || 1 != m.columns()) {
    throw DFT_exception("Incompatible input vector provided.");
  }
  matrix<complex> u = unitary_matrix();
  return u * m;
}
matrix<complex> DFT::dft_inv(const matrix<complex> &m) {
  if (num_pts != m.rows() || 1 != m.columns()) {
    throw DFT_exception("Incompatible input vectory provided.");
  }
  matrix<complex> inv = inverse_matrix();
  return inv * m;
}
