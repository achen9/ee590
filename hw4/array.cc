#include "array.hh"
#include "object.hh"
#include "null.hh"

Array::Array(void) {
  max = 10;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
  }
}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = array.values[i];
  }

}

Array& Array::operator=(const Array &other) {
  if (this != &other) {
    for (int i = 0; i < max; i++) {
      values[i] = other.values[i];
    }
  }
  return *this;
}

Array::~Array(void) {
  /*
  for (int i = 0; i < max; i++) {
    if (NULL != values[i]) {
      delete values[i];
    }
  }
  */
  delete []values;
}

void Array::set(int index, Object &object) {
  int new_max;
  Object **new_values;

  if (0 > index) {
    throw Object_Exception("Attempted to set negative index in array.");
  } else if (index >= max) {
    new_max = index + 10;
    new_values = new Object *[new_max];
    for (int i = 0; i < max; i++) {
      new_values[i] = values[i];
    }
    for (int i = max; i < new_max; i++) {
      new_values[i] = NULL;
    }
    delete values;
    max = new_max;
    values = new_values;
  }
  values[index] = object.clone();
}

Object* Array::get(int index) const {
  if ( 0 > index || max < index  ) {
    throw Object_Exception("Attempted to get out of bounds array element.");
  } else if (values[index] == NULL) {
    return new Null;
  }  else {
    return values[index];
  }
}

std::string Array::stringify(void) {

  std::string s = "[";

  int m = 0;

  for ( int i=0; i<max; i++ ) {
    if ( values[i] != NULL ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    if ( values[i] != NULL ) {
      s += values[i]->stringify();
    } else {
      s += "null";
    }
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}

int Array::length(void) {
  int len, i = max;
  do {
    i--;
    len = i + 1;
  } while (values[i] == NULL);
  return len;
}
