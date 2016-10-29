#pragma once
#include "object.hh"

class Null : public Object {
public:
  // Constructors & destructors
  inline Null(void) {}
  inline ~Null(void) {}

  Null * clone(void) { return new Null(*this); }
  std::string stringify(void) { return std::string("null"); }

};
