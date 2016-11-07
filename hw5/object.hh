#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>
#include <stdexcept>

class ObjectException : public std::runtime_error {
public:
  ObjectException(const char msg []) : std::runtime_error(msg) {}
};

class Object {

public:

  Object();
  Object ( const Object &m ) {}
  virtual ~Object() {}

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;
  virtual Object * get() const { throw "Undefined getter: get()"; }
  virtual Object * get(std::string s) const { throw "Undefined getter: get(s)"; }
  virtual Object * get(int i) const { throw "Undefined getter: get(i)"; }
  virtual bool is_null() { return false; }
  // For Number class only
  virtual inline void set_d(double d) { throw "Undefined setter: set_d()"; }
  virtual inline void set_i(int i) { throw "Undefined setter: set_i()"; }
  virtual double get_d(void) const { throw "Undefined getter: get_d()"; }
  virtual int get_i(void) const { throw "Undefined getter: get_i()"; }
  virtual bool is_int(void) const { throw "Undefined is_int()"; }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }

#endif
