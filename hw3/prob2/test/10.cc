#include "test.hh"
#include "complex.hh"

#define TOLERANCE 0.0001
#define PI 3.14159

int main ( int argc, char * argv[] ) {

  // PRINTING A COMPLEX NUMBER TESTS
  // This file tests printing a complex number by sending it
  // to cout and overloading the '<<' operator

  // TEST 1: Check 2.3-3.69j prints
  complex x(2.3, -3.69);
  std::cout << ' ' << x << ", ";

  // TEST 2: Check e^(j*pi) ~= -1 prints
  complex y1(0, PI);
  complex y = y1.exp();
  std::cout << y << ", ";

  // TEST 3: (3+4j)^5 ~= -237-3116j prints
  complex z1(3, 4);
  complex z = z1.pow(5);
  std::cout << z << ' ';
  SUCCEED;
}
