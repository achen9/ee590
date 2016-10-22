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
#include <math.h>
#include "complex.hh"

#define TOLERANCE 0.00000001

bool complex::isreal(void) const {
  if (TOLERANCE > abs(im())) {
    return true;
  } else {
    return false;
  }
}
bool complex::isimag(void) const {
  if (TOLERANCE > abs(re())) {
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
/*
complex complex::negate(void) const {
  complex negative = 1;
  if (0 > den()) {
    negative.set_num(num());
    negative.set_den(-den());
  } else {
    negative.set_num(-num());
    negative.set_den(den());
  }
  return negative;
}
bool complex::less_than(const fraction &f) const {
  if (0 > den() || 0 > f.den()) {
    // Need to add negative sign to num() and f.num() because 
    // negative in denominator causes comparison to be flipped
    return -num() * f.den() < -f.num() * den(); 
  } else {
    return num() * f.den() < f.num() * den();
  }
}
complex complex::power(int exp) const {
  complex f = 1;
  if (0 > exp) {
    // Negative exponents flip the fraction
    f.set_num(pow(den(), -exp));
    f.set_den(pow(num(), -exp));
  } else {
    f.set_num(pow(num(), exp));
    f.set_den(pow(den(), exp));
  }
  return f.reduce();
}
*/
