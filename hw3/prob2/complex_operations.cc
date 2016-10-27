/* NAME
 *  complex_operations.cc
 *
 * DESCRIPTION
 *  Defines methods for operations on the complex class
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
 * Alex Z. Chen - 10/20/2016
 * alexac9@uw.edu
 */
#include <iostream>
#include <cmath>
#include "complex.hh"

#define COMPLEX_TOL 0.0001

bool complex::isreal(void) const {
  if (COMPLEX_TOL > abs(im())) {
    return true;
  } else {
    return false;
  }
}
bool complex::isimag(void) const {
  if (COMPLEX_TOL > abs(re())) {
    return true;
  } else {
    return false;
  }
}
complex complex::delnegzero(void) const {
  complex nozero(re(), im());
  if (-0.0 == nozero.re()) {
    nozero.set_real(0.0);
  }
  if (-0.0 == nozero.im()) {
    nozero.set_imag(0.0);
  }
  return nozero;
}
complex complex::conjugate(void) const {
  complex c(re(), -im());
  return c.delnegzero();
}
complex complex::add(const complex &c) const {
  complex sum(re() + c.re(), im() + c.im());
  return sum.delnegzero();
}
complex complex::sub(const complex &c) const {
  complex difference(re() - c.re(), im() - c.im());
  return difference.delnegzero();
}
complex complex::mult(const complex &c) const {
  complex product(re()*c.re() - im()*c.im(), im()*c.re() + re()*c.im());
  return product.delnegzero();
}
complex complex::div(const complex &c) const {
  complex quotient = 0.0;
  complex num = *this * c.conjugate();
  complex den = c * c.conjugate();
  num = num.delnegzero();
  den = den.delnegzero();
  if (0.0 == den.re()) {
    throw complex_exception("Attempted to divide by zero.");
  } else if (!den.isreal()) {
    throw complex_exception("Complex conjugate did not produce real number in denominator.");
  }
  quotient.set_real(num.re() / den.re());
  quotient.set_imag(num.im() / den.re());
  return quotient.delnegzero();
}
complex complex::negate(void) const {
  complex negative(-re(), -im());
  return negative.delnegzero();
}
bool complex::equals(const complex &c) const {
  if (COMPLEX_TOL > std::abs(re() - c.re()) && COMPLEX_TOL > std::abs(im() - c.im())) {
    return true;
  } else {
    return false;
  }
}
complex complex::pow(int e) const {
  // Apply de Moivre's Formula: (r(cos(x) + isin(x)))^n = r^n(cos(nx) + isin(nx))
  complex c(std::pow(mag(), e)*std::cos(e*angle()), std::pow(mag(), e)*std::sin(e*angle()));
  return c.delnegzero();
}
complex complex::exp(void) const {
  // Apply Euler's formula re^(it) = r(cos(t) + isin(t))
  complex c(std::exp(re())*std::cos(im()), std::exp(re())*std::sin(im()));
  return c.delnegzero();
}