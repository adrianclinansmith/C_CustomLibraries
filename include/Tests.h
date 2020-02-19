/*
Tests.h
Functions for testing and debugging.

Adrian Clinansmith
April 20, 2019
*/

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <tgmath.h>

/****************************/
/*** return value testing ***/
/****************************/

/*
Macro that exchanges a datum for its format specifier as a string.
*/

#define FMT_SPEC(x)                                                            \
   _Generic((x),                                                               \
   bool:      "d",   char:  "c", char *: "s",  double:      "lf",              \
   float:     "f",   int:   "d", long:   "ld", long double: "Lf",              \
   long long: "lld", short: "d", size_t: "zu", default:     "n")               \

/*
Macro that prints a datum's name along with it's value to the standard output.
*/

#define SEE(x)                   \
   do {                          \
      char fmt[12] = "%s is %";  \
      strcat(fmt, FMT_SPEC(x));  \
      strcat(fmt, "\n");         \
      printf(fmt, #x, (x));      \
   } while (0)                   \

/*
Macro that prints a string's name and its value to the standard output, then
frees it.
*/

#define SEEFREE_STR(x)                          \
   do {                                         \
      char* s = (x);                            \
      printf("%s is %s\n", #x, s ? s : "NULL"); \
      if (s)                                    \
      {                                         \
         free(s);                               \
      }                                         \
   } while (0)                                  \

//#define STRINGIFY(x) stringifyFunc(&x, FMT_SPEC(x))
size_t stringify(void* p, char* fmtSpec);


/********************/
/*** print banner ***/
/********************/

/*
Prints 'title' to stdin as a "banner", for example:
**********
some title
**********
*/
void printBanner(const char* title);

/****************************/
/*** running time testing ***/
/****************************/

/*
Saves the current time in a private global variable that is separate from
stopTimer's variable.
*/

void startTimer();

/*
Saves the current time in a private global variable that is separate from
startTimer's variable.
*/

void stopTimer();

/*
Returns the amount of time in microsecond between startTimer stopTimer.
*/

long unsigned getTime();

/********************/
/*** file testing ***/
/********************/

/*
If 'func' is not NULL, func("dirnam/file", arg) is called for each file in
'dirname'. Otherwise if 'func' is NULL, each file name in 'dirname' is printed
to stdin. "dirnam/file" cannot be larger than 512 characters. File names
starting with a period will be skipped (i.e. .hiddenfile) If 'dirname' is NULL
or an invalid directory, false is returned, otherwise true is returned.
*/

bool eachFile(const char* dirname, void (*func)(char*, void*), void* arg);







#endif /* TESTS_H */
