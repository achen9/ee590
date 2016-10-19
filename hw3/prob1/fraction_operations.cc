/* NAME
 *  fraction_operations.cc
 *
 * DESCRIPTION
 *  Defines methods for operations on the fraction class
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
 * Alex Z. Chen - 10/19/2016
 * alexac9@uw.edu
 */
#include <iostream>
#include <math.h>
#include "fraction.hh"

fraction fraction::reduce(void) const {
  
  fraction fr = 1;
  int abs_num = abs(num());
  int abs_den = abs(den());
  int gcd = 1;

  // Modified Euclidean algorithm to find greatest common divisor (GCD)
  while (0 != abs_num && 0 != abs_den) {
    if (abs_num > abs_den) {
      gcd = abs_den;
      abs_num %= abs_den;
    } else {
      gcd = abs_num;
      abs_den %= abs_num;
    }
  }
  // Eliminate double negatives or move negative to numerator
  if (0 > den()) {
    gcd *= -1;
  }
  fr.set_num(num() / gcd);
  fr.set_den(den() / gcd);
  return fr;
}
fraction fraction::add(const fraction &f) const {
  fraction sum = 1;
  sum.set_num(f.den() * num() + den() * f.num());
  sum.set_den(den() * f.den());
  return sum.reduce();
}
fraction fraction::sub(const fraction &f) const {
  fraction difference = 1;
  difference.set_num(f.den() * num() - den() * f.num());
  difference.set_den(den() * f.den());
  return difference.reduce();
}
fraction fraction::mult(const fraction &f) const {
  fraction product = 1;
  product.set_num(num() * f.num());
  product.set_den(den() * f.den());
  return product.reduce();
}
fraction fraction::div(const fraction &f) const {
  fraction quotient = 1;
  if (0 == f.num()) {
    throw fraction_exception("Attempted to divide by zero.");
  }
  quotient.set_num(num() * f.den());
  quotient.set_den(den() * f.num());
  return quotient.reduce();
}
fraction fraction::negate(void) const {
  fraction negative = 1;
  if (0 > den()) {
    negative.set_num(num());
    negative.set_den(-den());
  } else {
    negative.set_num(-num());
    negative.set_den(den());
  }
  return negative;
}
bool fraction::less_than(const fraction &f) const {
  if (0 > den() || 0 > f.den()) {
    // Need to add negative sign to num() and f.num() because 
    // negative in denominator causes comparison to be flipped
    return -num() * f.den() < -f.num() * den(); 
  } else {
    return num() * f.den() < f.num() * den();
  }
}