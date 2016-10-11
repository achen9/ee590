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
    *C;

  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 );
  matrix_set ( A, 1, 0, 3 ); matrix_set ( A, 1, 1, 4 );

  printf("Beginning matrix_inverse() test...\n");
  C = matrix_inverse(A);
  matrix_print(C); NL;
  matrix_destroy(C);
  C = matrix_inverse(B);
  matrix_print(C);

  matrix_destroy(A);
  matrix_destroy(B);
  matrix_destroy(C);

  return 0;

}
