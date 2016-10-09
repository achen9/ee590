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
  int check;
  char *fgets_check;
  char *tmpfilename;

  fp = fopen(filename, "r");
  if (NULL == fp) {
    printf("Failed to open %s for reading. Please check the file name.\n", filename);
    return -1;
  }
  // Pop top item from stack
  fgets_check = fgets(buffer, BUF_SIZE, fp);
  if (NULL == fgets_check) {
    printf("Stack is empty!\n");
    return -1;
  } else {
    printf("%s", buffer);
  }
  // Store rest of stack in temp file
  tmpfilename = tmpnam(NULL);
  tmp = fopen(tmpfilename, "w");
  if (NULL == tmp) {
    printf("Failed to create temp file.\n");
    fclose(fp);
    return -1;
  }
  while (fgets(buffer, BUF_SIZE, fp) != NULL) {
    check = fputs(buffer, tmp);
    if (EOF == check) {
      printf("Failed to write to temp file.\n");
      fclose(tmp);
      fclose(fp);
      return -1;
    }
  } 
  fclose(tmp);
  fclose(fp);
  // Write contents of temp file to stack file
  tmp = fopen(tmpfilename, "r");
  if (NULL == tmp) {
    printf("Failed to open temp file for reading.\n");
    return -1;
  }
  fp = fopen(filename, "w");
  if (NULL == fp) {
    printf("Failed to open %s for writing.\n", filename);
    return -1;
  }
  while (fgets(buffer, BUF_SIZE, tmp) != NULL) {
    check = fputs(buffer, fp);
    if (EOF == check) {
      printf("Failed to write to %s\n", filename);
      fclose(tmp);
      fclose(fp);
      return -1;
    }
  }
  fclose(tmp);
  fclose(fp);
  // Delete temp file
  check = remove(tmpfilename);
  if (0 != check) {
    printf("Failed to delete temp file.\n");
    return -1;
  }
  return 0;
}
int print_top(char *filename) 
{
  FILE *fp;
  char buffer[BUF_SIZE];
  char *check;

  fp = fopen(filename, "r");
  if (NULL == fp) {
    printf("Failed to open file. Double check the file name.\n");
    return -1;
  }
  check = fgets(buffer, BUF_SIZE, fp);
  if (NULL == check) {
    printf("Stack is empty!\n");
    return -1;
  } else {
    printf("%s", buffer);
  }
  fclose(fp);
  return 0;
}
int swap_top(char *filename) 
{
  FILE *fp, *tmp;
  char buffer[BUF_SIZE];
  char stack_top[BUF_SIZE];
  int check;
  char *fgets_check;
  char *tmpfilename;

  fp = fopen(filename, "r");
  if (NULL == fp) {
    printf("Failed to open %s for reading. Please check the file name.\n", filename);
    return -1;
  }
  // Take top two items in stack
  fgets_check = fgets(stack_top, BUF_SIZE, fp);
  if (NULL == fgets_check) {
    printf("Stack is empty!\n");
    return -1;
  }
  fgets_check = fgets(buffer, BUF_SIZE, fp);
  if (NULL == fgets_check) {
    return 0; // Stack only has one element in it.
  }
  // Store modified stack in temp file
  tmpfilename = tmpnam(NULL);
  tmp = fopen(tmpfilename, "w");
  if (NULL == tmp) {
    printf("Failed to create temp file.\n");
    fclose(fp);
    return -1;
  }
  // Store second item in stack first
  check = fputs(buffer, tmp);
  if (EOF == check) {
    printf("Failed to write to temp file.\n");
    fclose(tmp);
    fclose(fp);
    return -1;
  }
  // Store top item in stack second
  check = fputs(stack_top, tmp);
  if (EOF == check) {
    printf("Failed to write to temp file.\n");
    fclose(tmp);
    fclose(fp);
    return -1;
  }
  // Populate rest of stack in temp file
  while (fgets(buffer, BUF_SIZE, fp) != EOF) {
    check = fputs(buffer, tmp);
    if (EOF == check) {
      printf("Failed to write to temp file.\n");
      fclose(tmp);
      fclose(fp);
      return -1;
    }
  }
  fclose(tmp);
  fclose(fp);
  // Write contents of temp file to stack file
  tmp = fopen(tmpfilename, "r");
  if (NULL == tmp) {
    printf("Failed to open temp file for reading.\n");
    return -1;
  }
  fp = fopen(filename, "w");
  if (NULL == fp) {
    printf("Failed to open %s for writing.\n", filename);
    return -1;
  }
  while (fgets(buffer, BUF_SIZE, tmp) != NULL) {
    check = fputs(buffer, fp);
    if (EOF == check) {
      printf("Failed to write to %s\n", filename);
      fclose(tmp);
      fclose(fp);
      return -1;
    }
  }
  fclose(tmp);
  fclose(fp);
  // Delete temp file
  check = remove(tmpfilename);
  if (0 != check) {
    printf("Failed to delete temp file.\n");
    return -1;
  }
  return 0;
}
int main(int argc, char *argv[])
{
  int check;

  // Check for correct # of inputs
  if (3 != argc) {
    printf("Incorrect number of inputs entered.\nPlease enter 2 inputs.\n");
    exit(-1);
  }
  // Identify stack command
  if (strcmp(argv[2], "pop") == 0) {
    check = pop(argv[1]);
    if (0 != check) {
      printf("Pop failed. See error message from pop above.\n");
      exit(-2);
    }
  } else if (strcmp(argv[2], "print_top") == 0) {
    check = print_top(argv[1]);
    if (0 != check) {
      printf("print_top failed. See error message from print_top above.\n");
      exit(-2);
    }
  } else if (strcmp(argv[2], "swap_top") == 0) {
    check = swap_top(argv[1]);
    if (0 != check) {
      printf("swap_top failed. See error message from swap_top above.\n");
      exit(-2);
    }
  } else {
    printf("Incorrect command entered.\n");
    exit(-3);
  }
  return 0;
}
