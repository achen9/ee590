#include "boolean.hh"

Boolean& Boolean::operator=(const Boolean &other) {
  if (this != &other) {
    value = other.value;
  }
  return *this;
}

std::string Boolean::stringify(void) {
  return value ? "true" : "false";
}
