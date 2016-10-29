#pragma once
#include "object.hh"

class Array : public Object {
public:
  // Constructors & destructors
  Array(void);
  Array ( const Array &array );
  Array * clone(void) { return new Array(*this); }
  ~Array(void);

  void set(int index, Object &object);
  Object * get(int index);
  std::string stringify(void);

private:
  int max;
  Object ** values;
};
