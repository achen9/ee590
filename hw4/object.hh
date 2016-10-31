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

  // Getters & setters
  virtual Object * get() const { throw Object_Exception("Undefined getter: get()"); }
  // For Hash class only
  virtual Object * get(std::string s) const { throw Object_Exception("Undefined getter: get(s)"); }
  // For Array class only
  virtual Object * get(int i) const { throw Object_Exception("Undefined getter: get(i)"); }
  // For String class only
  virtual std::string get_str() const { throw Object_Exception("Undefined getter get_str()"); }
  // For Number class only
  virtual double get_num() const { throw Object_Exception("Undefined getter get_num()"); }
  // For Boolean class only
  virtual bool get_bool() const { throw Object_Exception("Undefined getter get_bool()"); }

  // Utility methods
  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;
};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }
