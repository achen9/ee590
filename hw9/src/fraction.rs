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
  numerator: isize,
  denominator: isize,
}

// Constructors
pub fn fraction(n: isize, d: isize) -> Fraction {
  if 0 == d {
    panic!("Attempted to set denominator to 0");
  } 
  Fraction {numerator: n, denominator: d}
  /*f.set_num(n);
  f.set_den(d);
  return f;*/
}

// Methods
impl Fraction {
  // Getters
  pub fn num(&self) -> isize { (*self).numerator }
  pub fn den(&self) -> isize { (*self).denominator }

  // Setters
  pub fn set_num(&mut self, n: isize) { (*self).numerator = n; }
  pub fn set_den(&mut self, d: isize) {
    if 0 == d {
      panic!("Attempted to set denominator to 0");
    }
    (*self).denominator = d;
  }

  // Reduce method
 /* pub fn reduce(&self) -> Fraction {
    let mut gcd = 1;
    let mut abs_num = *self.num();
  }*/
}
