#pragma once
#include "object.hh"

class String : public Object {
public:
  // Constructors & destructors
  inline String(std::string s) : value(s) {}
  inline String(const String &string) { value = string.value; }
  inline String * clone(void) { return new String(*this); }
  inline ~String(void) {}

  // Getters and setters
  inline void set(std::string s) { value = s; }
  
  // Utility methods
  std::string stringify(void);

private:
  std::string value;
};
