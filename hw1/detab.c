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
 *
 * EXAMPLE
 *  ./detab file1 2
 *
 * NOTES
 *  Compile using gcc -o detab detab.c 
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
  fileName = argv[1];
  fp = fopen(filename, "r");
  while (*fp != EOF) {
    // Get next character in file stream until we reach the end of file
    nextChar = fgetc(fp);
    // If the character is a tab, print spaces. Otherwise, print the character
    if (nextChar == '\t') {
      for (i = 0; i < numSpaces; i++) {
        putchar(' ');
        }
    } else {
      putchar(nextChar);
    }
    // Increment file pointer to read next character in file
    fp++;
  }
  fclose(fp);
  putchar('\n');
  return 0;
}
