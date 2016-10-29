#include "string.hh"
#include "null.hh"

std::string String::stringify(void) {
  std::string s = "\"";
  s += value + "\"";
  return s;
}
