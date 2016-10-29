#include "array.hh"
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
 /*
  if (index > max) {
    new_max = max;
    new_values = new Object *[index + 10];
  }
  */
  values[index] = object.clone();
}

Object* Array::get(int index) {
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
