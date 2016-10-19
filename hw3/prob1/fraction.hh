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

private:
  int numerator;
  int denominator;
};
