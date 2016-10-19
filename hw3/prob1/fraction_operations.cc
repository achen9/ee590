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