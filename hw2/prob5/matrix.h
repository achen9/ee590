#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
  double * value;
  int rows;
  int columns;
} Matrix;

/* allocation and setup */
Matrix * matrix_new ( int rows, int columns );
void matrix_destroy ( Matrix * M );
Matrix * matrix_random ( int rows, int columns );
Matrix * matrix_from_file ( const char filename[] );

/* Getters and setters */
double matrix_get ( Matrix * M, int row, int column );
void matrix_set ( Matrix * M, int row, int column, double value );

/* print */
void matrix_print ( Matrix * M );

/* operations */
Matrix * matrix_add ( Matrix * A, Matrix * B );
Matrix * matrix_minor ( Matrix * M, int n );
double matrix_det(Matrix * M);
Matrix * matrix_scale(Matrix *M, double s); // return s * M, multiplying each element of M by s
Matrix * matrix_transpose(Matrix *M);       // return the transpose of M
Matrix * matrix_mult(Matrix *A, Matrix *B); // return A*B using matrix multiplication
Matrix * matrix_power(Matrix *M, int n);    // return M^n = M * M * ... * M (n times)
Matrix * matrix_inverse(Matrix *M);         // returns the inverse of M

/* utilities */
#define ASSERT(_cond_) {                                                          \
  if ( ! ( _cond_ ) ) {                                                           \
    fprintf (stderr, "Internal error: assertion '%s' failed at %s, line %d\n",    \
                   #_cond_ , __FILE__, __LINE__);                                 \
    exit ( -1 );                                                                  \
  }                                                                               \
}
Matrix * matrix_identity(int n);  // return the nxn identity matrix
int matrix_equal(Matrix *A, Matrix *B);     // return 1 if A == B (element wise) and 0 otherwise

#define NL printf ( "\n" );

#endif
