/* NAME
 *  stack.c
 *
 * DESCRIPTION
 *  Simulates a stack by using an input file to store stack variables
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
 *  ./stack testfile.txt pop
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

int pop(char *filename) 
{
  FILE *fp, *tmp;
  char buffer[BUF_SIZE];



  printf("pop() not implemented yet...\n");

  return 0;
}
int print_top(char *filename) 
{
  FILE *fp;
  char buffer[BUF_SIZE];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Failed to open file. Double check the file name.\n");
    return -1;
  }
  fgets(buffer, BUF_SIZE, fp);
  printf("%s", buffer);
  fclose(fp);

  return 0;
}
int swap_top(char *filename) 
{

  printf("swap_top() not implemented yet...\n");

  return 0;
}
int main(int argc, char *argv[])
{
  int check;

  // Check for correct # of inputs
  if (argc != 3) {
    printf("Incorrect number of inputs entered.\nPlease enter 2 inputs.\n");
    exit(-1);
  }
  // Identify stack command
  if (strcmp(argv[2], "pop") == 0) {
    check = pop(argv[1]);
    if (check != 0) {
      printf("Pop failed. See error message from pop above.\n");
      exit(-2);
    }
  } else if (strcmp(argv[2], "print_top") == 0) {
    check = print_top(argv[1]);
    if (check != 0) {
      printf("print_top failed. See error message from print_top above.\n");
      exit(-2);
    }
  } else if (strcmp(argv[2], "swap_top") == 0) {
    check = swap_top(argv[1]);
    if (check != 0) {
      printf("swap_top failed. See error message from swap_top above.\n");
      exit(-2);
    }
  } else {
    printf("Incorrect command entered.\n");
    exit(-3);
  }

  return 0;
}
