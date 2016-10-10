/* NAME
 *  day.c
 *
 * DESCRIPTION
 *  Converts between day of year and month/day
 *
 * PARAMETERS
 *  string year - year of interest
 *  string day_of_year - day of year of interest
 *
 * OR
 *
 * string year - year of interest
 * string month - month of interest
 * string day - day of month of interest
 *
 * RETURN
 *  0 - from main()
 *  -1 - Incorrect number of inputs entered
 *  -2 - Invalid input entered (e.g. negative year day)
 *
 * EXAMPLE
 *  ./day 1988 60 OR ./day 1988 2 29
 *
 * NOTES
 *  Compile using "gcc -o day day.c"
 *  If makefile is available, use "make day"
 *
 * Alex Z. Chen - 10/09/2016
 * alexac9@uw.edu
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static char *daytab[] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

long day_of_year(long year, long month, long day);
void month_day(long year, long yearday, long *pmonth, long *pday);

long day_of_year(long year, long month, long day)
{
  printf("day_of_year() not implemented yet...\n");
  return 0;
}
void month_day(long year, long yearday, long *pmonth, long *pday)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > *(*(daytab + leap) + i); i++) {
    yearday -= *(*(daytab + leap) + i);
  }
  *pmonth = i;
  *pday = yearday;
}
int main(int argc, char *argv[])
{
  long year = 0, month = 0, day = 0, yearday = 0;
  char *endp;

  year = strtol(argv[1], &endp, 10);
  if ('\0' != *endp) {
    printf("Invalid year entered.\nEnter a year between %ld and %ld", LONG_MIN, LONG_MAX);
  }
  if (3 == argc) {
    yearday = strtol(argv[2], NULL, 10);
    if (1 > yearday || 366 < yearday) {
      printf("Invalid yearday entered.\nEnter a yearday between 1 and 366.\n");
      exit(-2);
    }
    month_day(year, yearday, &month, &day);
    printf("%ld %ld", *pmonth, *pday);
  } else if (4 == argc) {
    month = strtol(argv[2], NULL, 10);
    if (1 > month || 12 < month) {
      printf("Invalid month entered.\nEnter a month between 1 and 12.\n");
      exit(-2);
    }
    day = strtol(argv[3], NULL, 10);
    if (1 > day || 31 < day) {
      printf("Invalid day entered.\nEnter a day between 1 and 31.\n");
      exit(-2);
    }
    yearday = day_of_year(year, month, day);
    printf("%ld", yearday);
  } else {
    printf("Incorrect number of inputs entered.\n");
    return -1;
  }
  return 0;
}