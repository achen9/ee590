/*
 * FSM Function Declarations
 */
#ifndef FSM
#define FSM

#define MAX_ALPHA 100
#define MAX_SUCCESS 100
#define MAX_INPUTS 100
#define MAX_STATES 100

int indexOf(char str[], char c);
int fsm ( char alphabet[], int num_rules, int rules[3][num_rules], const char str[] );
#endif
