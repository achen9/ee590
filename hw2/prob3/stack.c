/* NAME
 *  stack.c
 *
 * DESCRIPTION
 *  Replaces tabs with a specified number of spaces in a text file
 *
 * PARAMETERS
 *  string filename - file to perform changes on
 *  string "pop", "print_top", swap_top" - stack operation command
 *
 * RETURN
 *  0 - from main()
 *  -1 - Incorrect number of inputs entered
 *  -2 - Stack function failed
 *  -3 - Incorrect command given
 *
 * EXAMPLE
 *  ./detab detab_test.txt 2
 *
 * NOTES
 *  Compile using "gcc -o stack stack.c"
 *  If makefile is available, use "make stack"
 *
 * Alex Z. Chen - 10/08/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

int pop(char *filename);
int print_top(char *filename);
int swap_top(char *filename);

int pop(char *filename) {

  printf("pop() not implemented yet...\n");

  return 0;
}
int print_top(char *filename) {
  FILE *fp;
  char buffer[BUF_SIZE];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Failed to open file. Double check the file name.\n");
    return -1;
  }
  fgets(buffer, BUF_SIZE, fp);
  printf("%s", buffer);

  return 0;
}
int swap_top(char *filename) {

  printf("swap_top() not implemented yet...\n");

  return 0;
}
int main(int argc, char *argv[])
{
  int check;

  if (argc != 3) {
    printf("Incorrect number of inputs entered.\nPlease enter 2 inputs.\n");
    exit(-1);
  }
  switch (argv[2]) {
    case "pop":
      check = pop(argv[1]);
      if (check != 0) {
        printf("Pop failed. See error message from pop above.\n");
        exit(-2);
      }
      break;
    case "print_top":
      check = print_top(argv[1]);
      if (check != 0) {
        printf("print_top failed. See error message from print_top above.\n");
        exit(-2);
      }
      break;
    case "swap_top":
      check = swap_top(argv[1]);
      if (check != 0) {
        printf("swap_top failed. See error message from swap_top above.\n");
        exit(-2);
      }
      break;
    case default:
      printf("Incorrect command entered.\n");
      exit(-3);
  }

  return 0;
}