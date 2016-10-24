
template <class T>
matrix<T>::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new T[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = (T) 0;
  }

}

template <class T>
matrix<T>::~matrix() {
  delete []value;
}
/*
template <class T>
matrix<T> matrix<T>::random(int r, int c, T min, T max) {

  if (r <= 0 || c <= 0) {
    throw matrix_exception("Attempted to build a random matrix with non-positive number of rows and/or columns");
  }

  if (max <= min) {
    throw matrix_exception("Min is not less than max when building a random matrix");
  }

  matrix m(r, c);
  T d = max - min + 1,
    h = d / 2;

  for (int i = 0; i<r; i++) {
    for (int j = 0; j<c; j++) {
      m.set(i, j, rand() % d - h);
    }
  }

  return m;

}
*/
template <class T>
matrix<T> &matrix<T>::operator=(const matrix &other) {

  if (this != &other) {
    num_rows = other.num_rows;
    num_columns = other.num_columns;
    T * temp = new T[num_rows*num_columns];
    for (int i = 0; i<num_rows*num_columns; i++) {
      temp[i] = other.value[i];
    }
    delete[]value;
    value = temp;
  }

  return *this;

}

template <class T>
matrix<T> matrix<T>::identity(int s) {

  matrix m(s);
  T one = 1;

  for (int i = 0; i<s; i++) {
    m.set(i, i, one);
  }

  return m;

}

template <class T>
matrix<T> matrix<T>::ones(int r, int c) {

  matrix m(r, c);
  T one = 1;

  for (int i = 0; i<r; i++) {
    for (int j = 0; j<c; j++) {
      m.set(i, j, one);
    }
  }

  return m;

}

template <class T>
T matrix<T>::get(int r, int c) const {

  if (!in_range(r, c)) {
    throw matrix_exception("Indices out of range in matrix::get");
  }

  return value[r * columns() + c];

}

template <class T>
void matrix<T>::set(int r, int c, T x) {
  if (!in_range(r, c)) {
    throw matrix_exception("Indices out of range in matrix::set");
  }
  value[r * columns() + c] = x;
}

template <class T>
bool matrix<T>::in_range(int r, int c) const {
  return 0 <= r && r < rows() && 0 <= c && c < columns();
}

template <class T>
matrix<T> matrix<T>::add ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to add matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      M.set(i,j,(T) (get(i,j) + m.get(i,j))); /* NOTE: Casting result back to T */
    }
  }

  return M;

}

template <class T>
matrix<T> matrix<T>::mult(const matrix &m) const {

  if (columns() != m.rows()) {
    throw matrix_exception("Attemped to multiply matrices with incompatible sizes");
  }

  matrix M(rows(), columns());

  for (int i = 0; i<rows(); i++) {
    for (int j = 0; j<m.columns(); j++) {
      M.set(i, j, 0);
      for (int k = 0; k<columns(); k++) {
        M.set(i, j, M.get(i, j) + get(i, k) * m.get(k, j));
      }
    }
  }

  return M;

}

template <class T>
matrix<T> matrix<T>::scale(T d) const {
  matrix S(rows(), columns());
  for (int i = 0; i<rows(); i++) {
    for (int j = 0; j<columns(); j++) {
      S.set(i, j, d*get(i, j));
    }
  }
  return S;
}

template <class T>
bool matrix<T>::equals(const matrix &m) const {
  if (rows() != m.rows() || columns() != m.columns()) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for (int i = 0; i<rows(); i++) {
    for (int j = 0; j<columns(); j++) {
      if (get(i, j) != m.get(i, j)) {
        return false;
      }
    }
  }
  return true;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m) {

  for ( int i=0; i<m.rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      os << m.get(i,j) << '\t';
    }
    os << std::endl;
  }

  return os;

}

template <class T>
bool matrix<T>::less_than(const matrix & m) const {
  if (rows() != m.rows() || columns() != m.columns()) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for (int i = 0; i<rows(); i++) {
    for (int j = 0; j<columns(); j++) {
      if (get(i, j) >= m.get(i, j)) {
        return false;
      }
    }
  }
  return true;
}
