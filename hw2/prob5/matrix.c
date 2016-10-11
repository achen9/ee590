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
