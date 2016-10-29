#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class Object_Exception : public std::runtime_error {
public:
  Object_Exception(const char msg []) : std::runtime_error(msg) { }
};

class Object {
public:
  // Constructors & destructors
  Object(void);
  Object ( const Object &m ) {}
  virtual ~Object(void) {}

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;

  virtual Object * get() { throw Object_Exception("Undefined getter: get()"); }
  virtual Object * get(std::string s) { throw Object_Exception("Undefined getter: get(s)"); }
  virtual Object * get(int i) { throw Object_Exception("Undefined getter: get(i)"); }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }
