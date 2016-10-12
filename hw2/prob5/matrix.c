/* NAME
 *  day.c
 *
 * DESCRIPTION
 *  Defines matrix library functions. See functions for usage details.
 *
 *  This is a modified version of matrix.c written by Professor Eric Klavins for the University
 *  of Washington's Electrical Engineering Professional Master's Program (UW EE PMP) EE590
 *  course for autumn quarter 2016. His version can be found on his git repository at
 *  https://github.com/klavinslab/ee590.git.
 *
 * EXAMPLE
 *  #include "matrix.h"
 *
 * NOTES
 *  Compile using the makefile
 *
 * Alex Z. Chen - 10/09/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrix.h"

Matrix * matrix_new(int rows, int columns)
{
  Matrix * M = malloc(sizeof(Matrix));
  M->rows = rows;
  M->columns = columns;
  M->value = (double *) malloc(rows * columns * sizeof(double));
  return M;
}
void matrix_destroy(Matrix * M)
{
  free(M->value);
  free(M);
}
double matrix_get(Matrix * M, int row, int column)
{
  ASSERT(0 <= row && row < M->rows && 0 <= column && column < M->columns);
  return M->value[row * M->columns + column];
}
void matrix_set(Matrix * M, int row, int column, double value)
{
  ASSERT(0 <= row && row < M->rows && 0 <= column && column < M->columns);
  M->value[row * M->columns + column] = value;
}
void matrix_print(Matrix * M)
{
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      printf("%lf\t", matrix_get(M, i, j));
    }
    printf("\n");
  }
}
Matrix * matrix_random(int rows, int columns)
{
  Matrix * M = matrix_new(rows, columns);

  time_t t;
  srand((unsigned) time(&t));
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      matrix_set(M, i, j, rand() % 3 - 1);
    }
  }
  return M;
}
int matrix_equal(Matrix *A, Matrix *B)
{
  ASSERT(NULL != A || NULL != B);
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return 0;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (matrix_get(A, i, j) != matrix_get(B, i, j)) {
        return 0;
      }
    }
  }
  return 1;
}
Matrix * matrix_identity(int n)
{ 
  ASSERT(n > 0);
  Matrix * M = matrix_new(n, n);

  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      if (i == j) {
        matrix_set(M, i, j, 1.0);
      } else {
        matrix_set(M, i, j, 0.0);
      }
    }
  }
  return M;
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
    prev = DCAB;
    matrix_set(DCAB, 0, 0, 1.0 / matrix_get(prev, 0, 0));
    matrix_destroy(prev);
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
    matrix_destoy(DCAB);
    matrix_destroy(invA);
    matrix_destroy(B);
    matrix_destroy(C);
    matrix_destroy(D);
  }
  return P;
}
