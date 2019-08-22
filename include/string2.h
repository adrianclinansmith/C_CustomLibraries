/*
string2.h
Extends basic string functionality.

Adrian Clinansmith
April 20, 2019
*/

#ifndef STRING2_H
#define STRING2_H

#include <string.h>
#include <stdbool.h>

/******************/
/*** comparison ***/
/******************/

// returns true if str ends with case-insensitive substr, false otherwise
bool endsInsensitive(const char* str, const char* substr);

// returns true if str ends with substr, false otherwise
bool endsWith(const char* str, const char* substr);

// returns true if str1 and str2 are case-insensitive identical, false otherwise
bool equalsInsensitive(const char* str1, const char* str2);

// returns true if str starts with case-insensitive substr, false otherwise
bool startsInsensitive(const char* str, const char* substr);

// returns true if str starts with substr, false otherwise
bool startsWith(const char* str, const char* substr);

/*********************/
/*** concatenation ***/
/*********************/

// Appends at most n-1 characters of the formatted string 'format' to the end of 'str'.
// NULL is appended as the nth character, regardless of the length of 'format'.
// On success, the number of characters (minus NULL) that would be appended if n was large enough is returned.
// On failure, a negative number is returned.
int snprintcat(char* str, size_t n, const char* format, ...);

// Appends the formatted string 'format' to the end of 'str'.
// On success, the number of characters appended is returned (not including NULL).
// On failure, a negative number is returned.
int sprintcat(char* str, const char* format, ...);

/***************/
/*** copying ***/
/***************/

// Copies 'src' to 'dest' until the first occurrence of 'until' in 'src' is reached.
// The number of characters copied is returned.
// If 'until' is not a sub-string of 'src', no copying is done and 0 is returned.
size_t cpyUntil(char* dest, const char* src, const char* until);


/******************/
/*** inspection ***/
/******************/

// returns true if str is all digits (0 to 9), false otherwise
bool allDigits(const char* str);

// returns true if str is all white-space: " \t\n\v\f\r", false otherwise
bool allSpace(const char* str);

// returns the index of the first occurrence of c in str, or -1 if str doesn't contain c
int indexOfChar(const char* str, char c);

// returns true if str is a NULL pointer or all white-space: " \t\n\v\f\r", false otherwise
bool nullOrSpace(const char* str);

// Returns true if all characters in str evaluate to true (non-zero) by the function charIs().
// Returns false otherwise.
bool strIsAll(const char* str, int (*charIs)(int));








#endif
