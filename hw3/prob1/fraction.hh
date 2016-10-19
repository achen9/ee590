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
  ~fraction();

  // Getters
  inline int numerator(void) const { return num; }
  inline int denominator(void) const { return den; }

private:
  int num;
  int den;
};
