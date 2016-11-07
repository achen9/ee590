#include "number.hh"

Number::Number(double d) : d_value(d), i_value(0), is_integer(false) {
}

Number::Number(int i) : d_value(0.0), i_value(i), is_integer(true) {

}

double Number::get_d(void) const {
  if (is_integer) {
    return (double)i_value;
  } else {
    return d_value;
  }
}

int Number::get_i(void) const {
  if (!is_integer) {
    throw ObjectException("Attempted get_i() on a double value.");
  } else {
    return i_value;
  }
}

std::string Number::stringify() {
  if ( is_integer ) {
    return std::to_string(i_value);
  } else {
    return std::to_string(d_value);
  }
}
