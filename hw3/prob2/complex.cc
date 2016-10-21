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
/*
void complex::set_den(int d) {
  if (0 == d) {
    throw fraction_exception("Attempted to assign 0 to the denominator.");
  }
  imaginary = d;
}
std::ostream& operator<<(std::ostream& os, const complex &f) {
  os << f.re() << '/' << f.im();
  return os;
}
*/
