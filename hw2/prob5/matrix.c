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
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    return 0;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (A->value[i * A->columns + j] != B->value[i * B->columns + j]) {
        return 0;
      }
    }
  }
  return 1;
}
Matrix * matrix_identity(int n)
{ 
  Matrix * M = matrix_new(n, n);

  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      if (i == j) {
        M->value[i * M->columns + j] = 1.0;
      } else {
        M->value[i * M->columns + j] = 0.0;
      }
    }
  }
  return M;

}
