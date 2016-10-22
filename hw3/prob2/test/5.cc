#include "test.hh"
#include "complex.hh"
#include <cmath>

#define TOLERANCE 0.00001

int main ( int argc, char * argv[] ) {

  // ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION TESTS
  // This file tests the add(), sub(), mult(), and div() methods and their
  // corresponding operator overloads

  // TEST 1: Check 3.22+4.11j + -2.99-3.03j ~= 0.23+1.08j
  complex x1(3.22, 4.11);
  complex x2(-2.99, -3.03);
  complex x = x1 + x2;
  ASSERT(TOLERANCE > std::abs(x.re() - 0.23) && TOLERANCE > std::abs(x.im() - 1.08));

  // TEST 2: Check 4.25-9.28j - -3.21+6.56j ~= 7.46-15.84j
  complex y1(4.25, -9.28);
  complex y2(-3.21, 6.56);
  complex y = y1 - y2;
  ASSERT(TOLERANCE > std::abs(y.re() - 7.46) && TOLERANCE > std::abs(y.im() - -15.84));

  // Test 3: Check 2.34-0.0j * 0.0+6.22j ~= 0.0+14.5548
  complex z1(2.34, -0.0);
  complex z2(0.0, 6.22);
  complex z = z1 * z2;
  ASSERT(TOLERANCE > std::abs(z.re() - 0.0) && TOLERANCE > std::abs(z.im() - 14.5548));

  // TEST 4: Check 2.5+3.5j / 1-2j ~= -0.9+1.7j
  complex w1(2.5, 3.5);
  complex w2(1, -2);
  complex w = w1 / w2;
  ASSERT(TOLERANCE > std::abs(w.re() - -0.9) && TOLERANCE > std::abs(w.im() - 1.7));

  // TEST 5: Check 2.5+3.5j / -0-0j => error
  complex w3(-0, -0);
  try {
    w = w1 / w3;
  } catch(complex_exception &e){
    SUCCEED;
  }
  FAIL;
}
