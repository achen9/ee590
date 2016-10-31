#pragma once
#include "object.hh"
#include "array.hh"
#include "string.hh"

typedef struct _Bucket {
  std::string key;
  Object * value;
  _Bucket * next;
} Bucket;

class Hash : public Object {
public:
  // Constructors & destructors
  Hash(void);
  Hash(const Hash &hash);
  ~Hash(void);

  // Getters & setters
  Object * get(std::string key) const;
  void set(std::string key, Object &value);

  // Utility methods
  inline Hash * clone(void) { return new Hash(*this); }
  std::string stringify(void);
  Array keys(void) const;

private:
  int hash ( std::string s ) const;
  static const int num_shelves = 256;
  Bucket * shelves[num_shelves];
};
