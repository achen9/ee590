#pragma once
#include "object.hh"

class String : public Object {
public:
  // Constructors & destructors
  String(void) : value("") {}
  String(std::string s) : value(s) {}
  String(const String &string) { value = string.value; }
  String& operator=(const String &other);
  ~String(void) {}

  // Getters and setters
  inline std::string get_str(void) const { return value; }
  inline void set(std::string s) { value = s; }
  
  // Utility methods
  inline String * clone(void) { return new String(*this); }
  std::string stringify(void);

private:
  std::string value;
};
