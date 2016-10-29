#pragma once
#include "object.hh"

class Number : public Object {
public:
  // Constructors & destructors
  Number(double d);
  Number ( const Number &number ) { value = number.value; }
  inline ~Number(void) {}


  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  std::string stringify(void);

private:
  double value;
};
