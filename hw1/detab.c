/* NAME
 *  detab.c
 *
 * DESCRIPTION
 *  Replaces tabs with a specified number of spaces in a text file
 *
 * PARAMETERS
 *  string filename - file to perform changes on
 *  string n        - number of spaces to replace tabs with
 *
 * RETURN
 *  0 - from main()
 *  -1 - Incorrect number of inputs entered
 *  -2 - Negative number of spaces specified
 *  -3 - Could not open specified file
 *
 * EXAMPLE
 *  ./detab detab_test.txt 2
 *
 * NOTES
 *  Compile using "gcc -o detab detab.c"
 *  If makefile is available, use "make detab"
 *
 * Alex Z. Chen - 09/30/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *filename;
  char *spaces;
  int nextChar;
  int numSpaces;
  int i;
  FILE *fp;

  // Check for correct number of inputs
  if (argc != 3) {
    printf("Incorrect number of inputs entered.\nPlease enter 2 inputs.\n");
    exit(-1);
  }
  // Convert number of spaces to an integer
  spaces = argv[2];
  numSpaces = atoi(spaces);
  // Check if number of spaces specified is negative
  if (numSpaces < 0) {
    printf("Please enter zero or a postive for number of spaces.\n");
    exit(-2);
  }
  //Open file in read mode to start file stream
  filename = argv[1];
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open the file. Please check the file name.\n");
    exit(-3);
  }
  while ((nextChar = fgetc(fp)) != EOF) {
    // If the character is a tab, print spaces. Otherwise, print the character
    if (nextChar == '\t') {
      for (i = 0; i < numSpaces; i++) {
        putchar(' ');
        }
    } else {
      putchar(nextChar);
    }
  }
  fclose(fp);
  return 0;
}
