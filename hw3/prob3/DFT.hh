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
  ~DFT();

  // Copy constructor
  //DFT(const DFT &c);
  //DFT& operator=(const DFT &other);

  // Getters
  complex get(int n) const;

  // Setters
  void set(int n, complex c);

  //Discrete Fourier Transform Operations
  matrix<complex> transform_matrix(void);
  matrix<complex> unitary_matrix(void);
  matrix<complex> inverse_matrix(void);

  static std::map<int, matrix<complex>> dft_matrices;
  static std::map<int, matrix<complex>>::iterator it;

private:
  complex *points;
  int num_pts;
  
};
// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const DFT &c);
