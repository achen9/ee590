//! NAME
//!  fraction_tests.rs
//!
//! DESCRIPTION
//!  Unit test file for fraction class methods
//!
//! PARAMETERS
//!  See specific method
//!
//! RETURN
//!  See specific method
//! 
//! EXAMPLE
//!  See specific method
//!
//! NOTES
//!  Make sure the Cargo.toml file is available to compile the code
//!
//! Alex Z. Chen - 12/05/2016
//! alexac9@uw.edu
//!
extern crate matrix_lib;

// Test 1: Constructor test
#[test]
fn constructor() {
  use matrix_lib::fraction;
  let f: fraction::Fraction = fraction::fraction(2,3);
  assert_eq!(f.numerator,2);
  assert_eq!(f.denominator,3);
}
