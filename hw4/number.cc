#include "number.hh"

Number::Number(double d) : value(d) {
}

std::string Number::stringify(void) {
  return std::to_string(value);
}
