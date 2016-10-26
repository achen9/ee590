#pragma once
#include <iostream>
#include <stdexcept>
#include <map>
#include "complex.hh"
#include "matrix.hh"

class DFT_exception : public std::runtime_error {
public:
  DFT_exception(const char msg[]) : std::runtime_error(msg) {}
};

class DFT {
public:
  // Constructors and destructors
  DFT(int n);
  inline ~DFT() {}

  // Copy constructor
  //DFT(const DFT &c);
  //DFT& operator=(const DFT &other);

  // Getters
  inline int npts(void) { return num_pts; }

  //Discrete Fourier Transform Operations
  matrix<complex> transform_matrix(void);
  matrix<complex> unitary_matrix(void);
  matrix<complex> inverse_matrix(void);
  matrix<complex> conjugate_transpose(const matrix<complex> &m) const;
  matrix<complex> dft(const matrix<complex> &m);

  static std::map<int, matrix<complex>> dft_matrices;
  static std::map<int, matrix<complex>>::iterator it;

private:
  int num_pts;
  
};
// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const DFT &c);
