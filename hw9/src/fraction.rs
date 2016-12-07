//! NAME
//!  fraction.rs
//!
//! DESCRIPTION
//!  Module file that defines the fraction class
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

// Data definition
#[derive(Clone)]
pub struct Fraction {
  pub numerator: isize,
  pub denominator: isize,
}

// Constructors
pub fn fraction(n: isize, d: isize) -> Fraction {
  if 0 == d {
    panic!("Attempted to set denominator to 0");
  } 
  Fraction {numerator: n, denominator: d}
}


