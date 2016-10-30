#pragma once
#include "object.hh"

class Boolean : public Object {
public:
  // Constructors & destructors
  Boolean(void) : value(false) {}
  Boolean(bool b) : value(b) {}
  Boolean(const Boolean &boolean) { value = boolean.value; }
  Boolean& operator=(const Boolean &other);
  ~Boolean(void) {}

  // Getters and setters
  inline bool get_bool(void) const { return value; }
  inline void set(bool b) { value = b; }
  
  // Utility methods
  inline Boolean * clone(void) { return new Boolean(*this); }
  std::string stringify(void);

private:
  bool value;
};
