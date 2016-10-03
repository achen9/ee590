/* NAME
 *  reverse.c
 *
 * DESCRIPTION
 *  Outputs the reverse of an input text file to the terminal
 *
 * PARAMETERS
 *  string filename - file to perform changes on
 *
 * RETURN
 *  0 - from main()
 *  -1 - Incorrect number of inputs entered
 *  -2 - Could not open specified file
 *  -3 - fseek failed to find end of file
 *  -4 - ftell failed to return file stream position
 *  -5 - File exceeds file size limit
 *
 * EXAMPLE
 *  ./reverse reverse_test.txt
 *
 * NOTES
 *  Compile using gcc -o reverse reverse.c
 *  If makefile is available, use "make reverse"
 *  Files with more than 5000 characters are not allowed
 *
 * Alex Z. Chen - 10/01/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_LEN 5000

int main(int argc, char *argv[])
{
  char *filename;
  int check;
  long fileLen;
  long pos = 0;
  fpos_t *ptr;
  FILE *fp;
  int temp[MAX_FILE_LEN];
  int nextChar;
  
  // Check for correct number of inputs
  if (argc != 2) {
    printf("Incorrect number of inputs entered.\nPlease enter 1 input.\n");
    exit(-1);
  }
  //Open file in read mode to start file stream
  filename = argv[1];
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open the file. Please check the file name.\n");
    exit(-2);
  }
  // Find length of file
  check = fseek(fp, 0L, SEEK_END);
  if (check != 0) {
    printf("Error finding end of file.\n");
    fclose(fp);
    exit(-3);
  }
  fileLen = ftell(fp);
  if (fileLen < 0) {
    printf("Error extracting file length.\n");
    fclose(fp);
    exit(-4);
  } else if (fileLen > MAX_FILE_LEN) {
    printf("File is too big.\n");
    fclose(fp);
    exit(-5);
  }
  rewind(fp);
  // Add file content to temporary array storage
  while ((nextChar = fgetc(fp)) != EOF) {
    temp[(int)pos] = nextChar;
    pos++;
  }
  // Print file in reverse
  for (; pos >= 0; pos--) {
    putchar(temp[pos]);
  }
  putchar('\n');
  close(fp);
  return 0;
}
