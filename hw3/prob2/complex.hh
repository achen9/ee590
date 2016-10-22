#pragma once
#include <iostream>
#include <stdexcept>
#include <math.h>

class complex_exception : public std::runtime_error {
public:
  complex_exception(const char msg[]) : std::runtime_error(msg) {}
};

class complex {

public:
  // Constructors and destructors
  inline complex(double r, double i) : real(r), imaginary(i) {}
  complex(double r) : complex(r, 0.0) {}
  inline ~complex() {}

  // Copy constructor
  complex(const complex &c);
  complex& operator=(const complex &other);

  // Getters
  inline double re(void) const { return real; }
  inline double im(void) const { return imaginary; }

  // Setters
  inline void set_real(double r) { real = r; }
  inline void set_imag(double i) { imaginary = i; }
  
  // Complex Number Operations
  bool isreal(void) const; // check if complex number is real only
  bool isimag(void) const; // check if complex number is imaginary only
  complex delnegzero(void) const; // remove negative zeros from real or imaginary parts
  complex conjugate(void) const;
  complex add(const complex &c) const;
  complex sub(const complex &c) const;
  complex mult(const complex &c) const;
  complex div(const complex &c) const;
  complex negate(void) const;
  inline double mag(void) const { return sqrt(pow(re(), 2) + pow(im(), 2)); }
  inline double angle(void) const { return atan2(re(), im()); }
  // complex power(int exp) const;

  inline complex operator+(const complex &c) const { return add(c); }
  inline complex operator-(const complex &c) const { return sub(c); }
  inline complex operator*(const complex &c) const { return mult(c); }
  inline complex operator/(const complex &c) const { return div(c); }
  inline complex operator-(void) const { return negate(); }
  /*
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
