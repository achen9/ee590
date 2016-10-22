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
#include "fraction.hh"

fraction::fraction(int n, int d) : numerator(n), denominator(d) {
  if (0 == d) {
    throw fraction_exception("Attempted to assign 0 to the denominator.");
  } 
}
fraction::~fraction() {}
fraction::fraction(const fraction &f) {
  numerator = f.numerator;
  denominator = f.denominator;
}
fraction &fraction::operator=(const fraction &other) {
  if (this != &other) {
    numerator = other.numerator;
    denominator = other.denominator;
  }
  return *this;
}
void fraction::set_den(int d) {
  if (0 == d) {
    throw fraction_exception("Attempted to assign 0 to the denominator.");
  }
  denominator = d;
}
std::ostream& operator<<(std::ostream& os, const fraction &f) {
  os << f.num() << '/' << f.den();
  return os;
}
