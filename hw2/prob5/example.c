/* NAME
 *  day.c
 *
 * DESCRIPTION
 *  Runs library functions from matrix.c
 *
 * PARAMETERS
 *  none
 *
 * RETURN
 *  0 - from main()
 * -1 - Incorrect number of inputs entered
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

  Matrix * A = matrix_new ( 2, 2 ),
         * B = matrix_random ( 4, 4 ),
         * C;

  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 );
  matrix_set ( A, 1, 0, 3 ); matrix_set ( A, 1, 1, 4 );

  C = matrix_add ( A, A );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  matrix_print ( B ); NL;
  C = matrix_minor ( B, 1 );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  printf ( "det = %lf\n", matrix_det ( B ) );

  C = matrix_from_file ( "data/m1.mat" );
  matrix_print(C); NL;
  printf ( "det = %lf\n", matrix_det ( C ) );

  matrix_destroy(C);

  return 0;

}
