/* NAME
 *  example.c
 *
 * DESCRIPTION
 *  Runs library functions from matrix.c
 *
 * PARAMETERS
 *  none
 *
 * RETURN
 *  0 - from main()
 *
 * EXAMPLE
 *  ./example
 *
 * NOTES
 *  Compile using the makefile
 * 
 * Alex Z. Chen - 10/09/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include "matrix.h"

int main ( int argc, char * argv[] ) {

  Matrix * A = matrix_new(2, 2),
    *B = matrix_random(4, 4),
    *C,
    *D;
  int check;

  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 );
  matrix_set ( A, 1, 0, 3 ); matrix_set ( A, 1, 1, 4 );

  printf("Beginning matrix_equal() test...\n");
  C = matrix_add ( A, A );
  check = matrix_equal(C, A);
  printf("C == A? %d\n", check);
  check = matrix_equal(B, A);
  printf("B == A? %d\n", check);
  check = matrix_equal(A, A);
  printf("A == A? %d\n\n", check);

  printf("Beginning matrix_identity() test...\n");
  C = matrix_identity(4);
  matrix_print(C); NL;

  printf("Beginning matrix_scale() test...\n");
  D = matrix_scale(A, 2.5);
  matrix_print(A); NL;
  matrix_print(D); NL;
  matrix_destroy(D);
  D = matrix_scale(C, 0.0);
  matrix_print(C); NL;
  matrix_print(D); NL;
  matrix_destroy(D);

  printf("Beginning matrix_transpose() test...\n");
  matrix_print(A); NL;
  D = matrix_transpose(A);
  matrix_print(D); NL;
  matrix_destroy(C);
  matrix_destroy(D);
  C = matrix_random(2, 4);
  D = matrix_transpose(C);
  matrix_print(C); NL; 
  matrix_print(D); NL;
  matrix_destroy(B);
  matrix_destroy(D);

  printf("Beginning matrix_mult() test...\n");
  B = matrix_random(4, 1);
  D = matrix_mult(C, B);
  matrix_print(C); NL;
  matrix_print(B); NL;
  matrix_print(D); NL;

  printf("Beginning matrix_power() test...\n");
  matrix_destroy(B);
  matrix_print(A); NL;
  B = matrix_power(A, 5);
  matrix_print(B); NL;
  matrix_destroy(B);
  B = matrix_power(A, 0);
  matrix_print(B); NL;
  matrix_destroy(B);
  B = matrix_power(A, 1); 
  matrix_print(B);  NL;
  matrix_destroy(B);
  matrix_destroy(C);

  printf("Beginning matrix_inverse() test...\n");
  B = matrix_random(5, 5);
  C = matrix_inverse(A);
  matrix_print(C); NL;
  matrix_destroy(C);
  C = matrix_inverse(B);
  matrix_print(C);

  matrix_destroy(A);
  matrix_destroy(B);
  matrix_destroy(C);
  matrix_destroy(D);

  return 0;

}
