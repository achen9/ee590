#pragma once
#include "object.hh"

class Null : public Object {
public:
  // Constructors & destructors
  Null(void) {}
  ~Null(void) {}

  // Utility methods
  inline Null * clone(void) { return new Null(*this); }
  inline std::string stringify(void) { return std::string("null"); }

};
