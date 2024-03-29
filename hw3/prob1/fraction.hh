#pragma once
#include <iostream>
#include <stdexcept>

class fraction_exception : public std::runtime_error {
public:
  fraction_exception(const char msg[]) : std::runtime_error(msg) {}
};

class fraction {

public:
  // Constructors and destructors
  fraction(int n, int d);
  fraction(int w) : fraction(w, 1) {}
  fraction(void) : fraction(0, 1) {}
  ~fraction();

  // Copy constructor
  fraction(const fraction &f);
  fraction& operator=(const fraction &other);

  // Getters
  inline int num(void) const { return numerator; }
  inline int den(void) const { return denominator; }

  // Setters
  inline void set_num(int n) { numerator = n; }
  void set_den(int d);

  // Fraction Operations
  fraction reduce(void) const;
  fraction add(const fraction &f) const;
  fraction sub(const fraction &f) const;
  fraction mult(const fraction &f) const;
  fraction div(const fraction &f) const;
  fraction negate(void) const;
  inline bool equals(const fraction &f) const { return num() * f.den() == f.num() * den(); }
  bool less_than(const fraction &f) const;
  fraction pow(int e) const;
  
  inline fraction operator+(const fraction &f) const { return add(f); }
  inline fraction operator-(const fraction &f) const { return sub(f); }
  inline fraction operator*(const fraction &f) const { return mult(f); }
  inline fraction operator/(const fraction &f) const { return div(f); }
  inline fraction operator-(void) const { return negate(); }
  inline bool operator==(const fraction &f) const { return equals(f); }
  inline bool operator!=(const fraction &f) const { return !equals(f); }
  inline bool operator<(const fraction &f) const { return less_than(f); }
  inline bool operator>(const fraction &f) const { return !less_than(f); }
  inline bool operator<=(const fraction &f) const { return less_than(f) || equals(f); }
  inline bool operator>=(const fraction &f) const { return !less_than(f) || equals(f); }

private:
  int numerator;
  int denominator;
};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const fraction &f);
