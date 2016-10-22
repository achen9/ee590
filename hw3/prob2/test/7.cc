#include "test.hh"
#include "complex.hh"
#include <cmath>

#define TOLERANCE 0.0001
#define PI 3.14159

int main ( int argc, char * argv[] ) {

  // MAGNITDUE AND ANGLE METHODS TEST
  // This file tests the mag() and angle() methods to calculate the magnitude
  // and angle of a complex number

  // TEST 1: Check mag(3+4j) ~= 5 and angle(3+4j) ~= 0.927295
  complex x(3, 4);
  ASSERT(TOLERANCE > std::abs(x.mag() - 5.0));
  ASSERT(TOLERANCE > std::abs(x.angle() - 0.927295))

  // TEST 2: Check mag(-2.34-6.98j) ~= 7.36179 and angle(-2.34-6.98j) ~= -1.89427
  complex y(-2.34, -6.98);
  ASSERT(TOLERANCE > std::abs(y.mag() - 7.36179));
  ASSERT(TOLERANCE > std::abs(y.angle() + 1.89427));

  // TEST 3: Check mag(-0.0-0.0j) ~= 0 and angle(-0.0-0.0j) ~= -3.141592
  // NOTE: The angle test may fail on other machines depending on the
  // implementation of the atan2() function. Should the angle test
  // fail, I print out a message instead of triggering an assertion failure
  complex z(-0.0, -0.0);
  ASSERT(TOLERANCE > std::abs(z.mag() - 0.0));
  if (!(TOLERANCE > std::abs(z.angle() + PI))) {
    std::cout << std::endl << "atan2(-0,-0) is defined to be " << z.angle();
    std::cout << " on this machine." << std::endl;
    std::cout << "It is different than -3.14159 defined on my test machine." << std::endl;
  }
  SUCCEED;
}
