#pragma once
#include <iostream>
#include <stdexcept>

class complex_exception : public std::runtime_error {
public:
  complex_exception(const char msg[]) : std::runtime_error(msg) {}
};

class complex {

public:
  // Constructors and destructors
  inline complex(double r, double i) : real(r), imaginary(i) {}
  //complex(double w) : complex(w, 0) {}
  inline ~complex() {}

  // Copy constructor
  complex(const complex &c);
  complex& operator=(const complex &other);

  // Getters
  inline double re(void) const { return real; }
  inline double im(void) const { return imaginary; }

  // Setters
  inline void set_real(int r) { real = r; }
  inline void set_imag(int i) { imaginary = i; }
  /*
  // Fraction Operations
  complex reduce(void) const;
  complex add(const complex &f) const;
  complex sub(const complex &f) const;
  complex mult(const complex &f) const;
  complex div(const complex &f) const;
  complex negate(void) const;
  inline bool equals(const complex &f) const { return re() * f.im() == f.re() * im(); }
  bool less_than(const complex &f) const;
  complex power(int exp) const;
  
  inline complex operator+(const complex &f) { return add(f); }
  inline complex operator-(const complex &f) { return sub(f); }
  inline complex operator*(const complex &f) { return mult(f); }
  inline complex operator/(const complex &f) { return div(f); }
  inline complex operator-(void) { return negate(); }
  inline bool operator==(const complex &f) { return equals(f); }
  inline bool operator!=(const complex &f) { return !equals(f); }
  inline bool operator<(const complex &f) { return less_than(f); }
  inline bool operator>(const complex &f) { return !less_than(f); }
  inline bool operator<=(const complex &f) { return less_than(f) || equals(f); }
  inline bool operator>=(const complex &f) { return !less_than(f) || equals(f); }
  */
private:
  double real;
  double imaginary;
};

// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const complex &f);
