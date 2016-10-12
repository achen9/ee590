#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_add ( Matrix * A, Matrix * B ) {

  ASSERT ( A->rows == B->rows && A->columns == B->columns );

  Matrix * C = matrix_new ( A->rows, A->columns );

  for ( int i=0; i<A->rows; i++ ) {
    for ( int j=0; j<A->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(A,i,j) + matrix_get(B,i,j) );
    }
  }

  return C;

}

Matrix * matrix_minor ( Matrix * M, int n ) {

  ASSERT ( 0 <= n && n < M->columns );

  Matrix * P = matrix_new ( M->rows - 1, M->columns - 1 );

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=0; j<n; j++ ) {
      matrix_set(P,i-1,j,matrix_get(M,i,j));
    }
  }

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=n+1; j<M->columns; j++ ) {
      matrix_set(P,i-1,j-1,matrix_get(M,i,j));
    }
  }

  return P;

}

double matrix_det ( Matrix * M ) {

  if ( M->rows == 1 && M->columns == 1 ) {

    return matrix_get(M,0,0);

  } else {

    double sign = 1,
           sum = 0;

    for ( int i=0; i<M->columns; i++ ) {
      Matrix * P = matrix_minor ( M, i );
      sum += sign * matrix_get(M,0,i) * matrix_det(P);
      sign *= -1;
      matrix_destroy ( P );
    }

    return sum;

  }


}
Matrix * matrix_scale(Matrix *M, double s)
{
  ASSERT(NULL != M);
  Matrix *sM = matrix_new(M->rows, M->columns);

  for (int i = 0; i < sM->rows; i++) {
    for (int j = 0; j < sM->columns; j++) {
      matrix_set(sM, i, j, matrix_get(M, i, j)*s);
    }
  }
  return sM;
}
Matrix * matrix_transpose(Matrix *M)
{
  ASSERT(NULL != M);
  Matrix *T = matrix_new(M->columns, M->rows);

  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      matrix_set(T, j, i, matrix_get(M, i, j));
    }
  }
  return T;
}
Matrix * matrix_mult(Matrix *A, Matrix *B)
{
  ASSERT(A->columns == B->rows);
  Matrix *M = matrix_new(A->rows, B->columns);

  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      matrix_set(M, i, j, 0.0);
      for (int k = 0; k < A->columns; k++) {
        matrix_set(M, i, j, matrix_get(M, i, j) + (matrix_get(A, i, k) * matrix_get(B, k, j)));
      }
    }
  }
  return M;
}
Matrix * matrix_power(Matrix *M, int n)
{
  ASSERT(0 <= n);
  ASSERT(M->rows == M->columns);
  Matrix *P, *prev;

  if (0 == n) {
    P = matrix_identity(M->rows);
  } else {
    P = matrix_new(M->rows, M->columns);
    for (int i = 0; i < M->rows; i++) {
      for (int j = 0; j < M->columns; j++) {
        matrix_set(P, i, j, matrix_get(M, i, j));
      }
    }
  }
  for (int i = 1; i < n; i++) {
    prev = P;
    P = matrix_mult(P, M);
    matrix_destroy(prev);
  }
  return P;
}
Matrix * matrix_inverse(Matrix *M)
{
  ASSERT(NULL != M);
  ASSERT(M->rows == M->columns);
  Matrix *P, *Pnext, *invA, *B, *C, *D, *DCAB, *tmp, *prev;
  double det;

  det = matrix_det(M);
  if (0.0 == det) {
    printf("Matrix is singular. Determinant is zero.\n");
    exit(-1);
  } else if (1 == M->rows) {
    P = matrix_new(M->rows, M->columns);
    matrix_set(P, 0, 0, 1.0 / matrix_get(M, 0, 0));
  } else {
    Pnext = matrix_new(M->rows - 1, M->columns - 1);
    for (int i = 0; i < Pnext->rows; i++) {
      for (int j = 0; j < Pnext->columns; j++) {
        matrix_set(Pnext, i, j, matrix_get(M, i, j));
      }
    }
    invA = matrix_inverse(Pnext);
    matrix_destroy(Pnext);
    B = matrix_new(M->rows - 1, 1);
    C = matrix_new(1, M->columns - 1);
    D = matrix_new(1, 1);
    for (int i = 0; i < M->rows - 1; i++) {
      matrix_set(B, i, 0, matrix_get(M, i, M->columns - 1));
      matrix_set(C, 0, i, matrix_get(M, M->rows - 1, i));
    }
    matrix_set(D, 0, 0, matrix_get(M, M->rows - 1, M->columns - 1));
    P = matrix_new(M->rows, M->columns);
    // Compute DCAB = inv(D - C*inv(A)*B)
    DCAB = matrix_mult(invA, B);
    prev = DCAB;
    DCAB = matrix_mult(C, prev);
    matrix_destroy(prev);
    prev = DCAB;
    DCAB = matrix_scale(prev, -1.0);
    matrix_destroy(prev);
    prev = DCAB;
    DCAB = matrix_add(D, prev);
    matrix_destroy(prev);
    matrix_set(DCAB, 0, 0, 1.0 / matrix_get(DCAB, 0, 0));
    // Compute top left term: inv(A) + inv(A)*B*DCAB*C*inv(A)
    tmp = matrix_mult(DCAB, C);
    prev = tmp;
    tmp = matrix_mult(prev, invA);
    matrix_destroy(prev);
    prev = tmp;
    tmp = matrix_mult(B, prev);
    matrix_destroy(prev);
    prev = tmp;
    tmp = matrix_mult(invA, prev);
    matrix_destroy(prev);
    prev = tmp;
    tmp = matrix_add(invA, prev);
    matrix_destroy(prev);
    for (int i = 0; i < tmp->rows; i++) {
      for (int j = 0; j < tmp->columns; j++) {
        matrix_set(P, i, j, matrix_get(tmp, i, j));
      }
    }
    matrix_destroy(tmp);
    // Compute top right term: -inv(A)*B*DCAB
    tmp = matrix_mult(B, DCAB);
    prev = tmp;
    tmp = matrix_mult(invA, prev);
    matrix_destroy(prev);
    prev = tmp;
    tmp = matrix_scale(prev, -1.0);
    matrix_destroy(prev);
    for (int i = 0; i < tmp->rows; i++) {
      matrix_set(P, i, P->columns - 1, matrix_get(tmp, i, 0));
    }
    matrix_destroy(tmp);
    // Compute bottom left term: -DCAB*C*inv(A)
    tmp = matrix_mult(DCAB, C);
    prev = tmp;
    tmp = matrix_mult(prev, invA);
    matrix_destroy(prev);
    prev = tmp;
    tmp = matrix_scale(prev, -1.0);
    matrix_destroy(prev);
    for (int i = 0; i < tmp->columns; i++) {
      matrix_set(P, P->rows - 1, i, matrix_get(tmp, 0, i));
    }
    matrix_destroy(tmp);
    // Compute bottom right term: DCAB
    matrix_set(P, P->rows - 1, P->columns - 1, matrix_get(DCAB, 0, 0));
    matrix_destroy(DCAB);
    matrix_destroy(invA);
    matrix_destroy(B);
    matrix_destroy(C);
    matrix_destroy(D);
  }
  return P;
}
