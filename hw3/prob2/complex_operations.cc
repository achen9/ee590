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

complex complex::conjugate(void) const {
  complex c = re();
  if (0.0 == im()) {
    // Prevent negative zero from being stored as imaginary part
    c.set_imag(0.0); 
  } else {
    c.set_imag(-im());
  }
  return c;
}
/*
complex complex::add(const complex &f) const {
  complex sum = 1;
  sum.set_num(f.den() * num() + den() * f.num());
  sum.set_den(den() * f.den());
  return sum.reduce();
}
complex complex::sub(const complex &f) const {
  complex difference = 1;
  difference.set_num(f.den() * num() - den() * f.num());
  difference.set_den(den() * f.den());
  return difference.reduce();
}
complex complex::mult(const complex &f) const {
  complex product = 1;
  product.set_num(num() * f.num());
  product.set_den(den() * f.den());
  return product.reduce();
}
complex complex::div(const complex &f) const {
  complex quotient = 1;
  if (0 == f.num()) {
    throw complex_exception("Attempted to divide by zero.");
  }
  quotient.set_num(num() * f.den());
  quotient.set_den(den() * f.num());
  return quotient.reduce();
}
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
