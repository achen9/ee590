#include "string.hh"
#include "null.hh"

String& String::operator=(const String &other) {
  if (this != &other) {
    value = other.value;
  }
  return *this;
}

std::string String::stringify(void) {
  std::string s = "\"";
  s += value + "\"";
  return s;
}
