#pragma once
#include "object.hh"

class Number : public Object {
public:
  // Constructors & destructors
  Number(double d);
  Number ( const Number &number ) { value = number.value; }
  inline ~Number(void) {}

  // Getters & setters
  inline void set(double d) { value = d; }

  // Utility methods
  Number * clone() { return new Number(*this); }
  std::string stringify(void);

private:
  double value;
};
