#pragma once
#include "object.hh"

class Array : public Object {
public:
  // Constructors & destructors
  Array(void);
  Array ( const Array &array );
  Array& operator=(const Array &other);
  ~Array(void);

  // Getters & setters
  void set(int index, Object &object);
  Object * get(int index);
  inline int get_max(void) { return max; }

  // Utility methods
  Array * clone(void) { return new Array(*this); }
  std::string stringify(void);
  int length(void);

private:
  int max;
  Object ** values;
};
