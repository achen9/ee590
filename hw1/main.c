/* NAME
 *  main.c
 *
 * DESCRIPTION
 *  Takes an input finite state machine (FSM), defined in a csv file format, and a regular
 *  expression test string to execute the FSM on.
 *
 *  This is a modified version of main.c written by Professor Eric Klavins for the University
 *  of Washington's Electrical Engineering Professional Master's Program (UW EE PMP) EE590
 *  course for autumn quarter 2016. His version can be found on his git repository at
 *  https://github.com/klavinslab/ee590.git.
 *
 * PARAMETERS
 *  string filename   - csv file defining the FSM
 *  string expression - regular expression to evaluate the FSM on
 *
 * RETURN
 *  0 - from main()
 * -1 - not enough inputs error
 * -2 - failed to open the file
 * -3 - failed to read line from file using fgets()
 *
 * EXAMPLE
 *  ./fsm fsm.csv 0.123 for a valid decimal number
 *
 * NOTES
 *  Compile using "gcc -c main.c fsm.c
 *                 gcc -o fsm main.o fsm.o"
 *  If makefile is available, use "make fsm"
 *
 *  Character alphabet input assumes unique character set is given.
 *  Number of inputs and states cannot exceed 100 each.
 *
 * Alex Z. Chen - 10/02/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fsm.h"

int main ( int argc, char * argv[] )
{
  FILE *fp;
  int nextChar;
  int pos;
  int numInput;
  int numState;
  int col;
  int row;
  char *token;
  /* Input alphabet */
  char alphabet[MAX_ALPHA];
  char fsmRowBuffer[MAX_STATES * 4];
  /*
     Example Regular Expression: ab*c
     0 -a-> 1                2 = ACCEPT
     1 -b-> 1                3 = REJECT
     1 -c-> 2
   */
  /* Matrix implementation. Maximum 100 inputs and 100 states*/
  int rules[MAX_INPUTS][MAX_STATES];
  /* Check the input string */
  char *filename;
  char * input;
  
  if (argc != 3) {
    printf("Incorrect number of inputs entered.\nPlease enter 2 inputs.\n");
    exit(-1);
  }
  filename = argv[1];
  input = argv[2];
  // Open csv file defining the FSM
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file. Please check the file name.\n");
    fclose(fp);
    exit(-2);
  }
  // Assume 1st line in csv file is alphabet
  pos = 0;
  if (fgets(alphabet, MAX_ALPHA, fp) == NULL) {
    printf("Failed to read first line from file. Please check the file.\n");
    fclose(fp);
    exit(-3);
  }
  alphabet[strcspn(alphabet,"\n")] = '\0'; // Eliminate newline from alphabet
  // Discard 2nd line in csv file
  if (fgets(fsmRowBuffer, MAX_STATES * 4, fp) == NULL) {
    printf("Failed to read second line from file. Please check the file.\n");
    fclose(fp);
    exit(-3);
  }
  // Get FSM matrix one line at a time. Parse the line for the comma separated values.
  row = 0;
  while (fgets(fsmRowBuffer, MAX_STATES * 4, fp) != NULL) {
    fsmRowBuffer[strcspn(fsmRowBuffer, "\n")] = '\0';
    col = 0;
    token = strtok(fsmRowBuffer, ",");
    rules[row][col] = atoi(token);
    col++;
    while (token != NULL) {
      token = strtok(NULL, ",");
      rules[row][col] = atoi(token);
      col++;
    }
    row++;
  }
  fclose(fp);
  numState = col;
  numInput = strlen(alphabet);
  if ( fsm(alphabet,numState,rules,input) < numState ) {
    printf ( "accept\n");
  } else {
    printf ( "reject\n");
  }
  return 0;
}
