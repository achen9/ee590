/* NAME
 *  fraction.cc
 *
 * DESCRIPTION
 *  Defines methods for fraction class
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
#include "fraction.hh"

fraction::fraction(int n, int d) : num(n), den(d) {
  if (0 == d) {
    throw fraction_exception("Attempted to assign 0 to the denominator.");
  } 
}
fraction::~fraction() {}
fraction::fraction(const fraction &f) {
  num = f.num;
  den = f.den;
}
fraction &fraction::operator=(const fraction &other) {
  if (this != &other) {
    num = other.num;
    den = other.den;
  }
  return *this;
}
