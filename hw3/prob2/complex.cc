/* NAME
 *  complex.cc
 *
 * DESCRIPTION
 *  Defines methods for complex class
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
 * Alex Z. Chen - 10/18/2016
 * alexac9@uw.edu
 */
#include <iostream>
#include <math.h>
#include <random>
#include "complex.hh"

complex::complex(const complex &c) {
  real = c.re();
  imaginary = c.im();
}
complex &complex::operator=(const complex &other) {
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
complex complex::random(double min, double max) {
  double r, i;
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(min, max);
  r = distribution(generator);
  i = distribution(generator);
  complex rc(r, i);
  return rc;
}
