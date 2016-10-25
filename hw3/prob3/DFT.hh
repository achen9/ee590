#pragma once
#include <iostream>
#include <stdexcept>
#include "complex.hh"

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
  //inline void set_real(double r) { real = r; }
  //inline void set_imag(double i) { imaginary = i; }

private:
  complex *points;
  int numPoints;
};

// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const DFT &c);
