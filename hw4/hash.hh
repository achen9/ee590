#pragma once
#include "object.hh"

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

  Hash * clone() { return new Hash(*this); }
  void set ( std::string key, Object &value);
  Object * get ( std::string key );
  std::string stringify(void);

private:
  int hash ( std::string s );
  static const int num_shelves = 256;
  Bucket * shelves[num_shelves];
};
