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

// Constructor Test 1: Test if 2/3 can be assigned to a fraction 
#[test]
fn constructor_test1() {
  use matrix_lib::fraction;
  let f: fraction::Fraction = fraction::fraction(2,3);
  assert_eq!(f.num(),2);
  assert_eq!(f.den(),3);
  
}
// Constructor Test 2: Test if setting denominator to 0 will cause panic
#[test]
#[should_panic]
fn constructor_test2() {
  use matrix_lib::fraction;
  let f1: fraction::Fraction = fraction::fraction(2,0);
}
// Copy Constructor Test 1: Test if fraction -3/4 can be copied to another variable
#[test]
fn copy_constructor_test() {
  use matrix_lib::fraction;
  let f1: fraction::Fraction = fraction::fraction(-3,4);
  let mut f2: fraction::Fraction = f1.clone();
  assert_eq!(f2.num(),-3);
  assert_eq!(f2.den(),4);
  f2.set_num(5);
  assert_eq!(f2.num(),5);
  assert_eq!(f1.num(),-3);
}
