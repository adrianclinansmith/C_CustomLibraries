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
#include <stdlib.h>

/******************/
/*** comparison ***/
/******************/

/*
Returns true if str ends with case-insensitive substr, false otherwise.
Two nulls returns true, one null returns false.
*/

bool endsInsensitive(const char* str, const char* substr);

/*
Returns true if str ends with substr, false otherwise.
Two nulls returns true, one null returns false.
*/

bool endsWith(const char* str, const char* substr);

/*
Returns true if null-terminated str1 & str2 are identical, false otherwise.
Two nulls returns true, one null returns false.
*/

bool equals(const char* str1, const char* str2);

/*
Returns true if null-terminated str1 & str2 are case-insensitive identical,
false otherwise. Two nulls returns true, one null returns false.
*/

bool equalsInsensitive(const char* str1, const char* str2);

/*
Returns true if str starts with case-insensitive substr, false otherwise.
Two nulls returns true, one null returns false.
*/

bool startsInsensitive(const char* str, const char* substr);

/*
Returns true if str starts with substr, false otherwise.
Two nulls returns true, one null returns false.
*/

bool startsWith(const char* str, const char* substr);

/*********************/
/*** concatenation ***/
/*********************/
 /*
Appends at most n-1 characters of the formatted string 'format' to the end of 'str'.
NULL is appended as the nth character, regardless of the length of 'format'.
On success, the number of characters (minus NULL) that would be appended if n
was large enough is returned. On failure, a negative number is returned.
*/

int snprintcat(char* str, size_t n, const char* format, ...);

/*
Appends the formatted string 'format' to the end of 'str'.
On success, the number of characters appended is returned (not including NULL).
On failure, a negative number is returned.
*/

int sprintcat(char* str, const char* format, ...);

/***************/
/*** copying ***/
/***************/

/*
Copies 'src' to 'dest' until the first occurrence of 'until' in 'src' is reached.
The number of characters copied is returned.
If 'until' is not a sub-string of 'src', no copying is done and 0 is returned.
*/

size_t cpyUntil(char* dest, const char* src, const char* until);


/******************/
/*** inspection ***/
/******************/

/*
Returns true if null-terminated str is all digits, 0-9, false otherwise.
*/

bool allDigits(const char* str);

/*
Returns true if null-terminated str is all white-space: " \t\n\v\f\r",
false otherwise.
*/

bool allSpace(const char* str);

/*
Returns the index of the first occurrence of character c in null-terminated str,
or -1 if str doesn't contain the character. If str is null, -2 is returned.
*/

int indexOfChar(const char* str, char c);

/*
Returns true if str is null or starts with '\0', false otherwise.
*/

bool nullOrEmpty(const char* str);

/*
Returns true if str is null or all white-space: " \t\n\v\f\r", false otherwise.
*/

bool nullOrSpace(const char* str);

/*
Returns true if all characters in str evaluate to true (non-zero) by the
function charIs(), excluding the terminating null, false otherwise.
Consequently, if str starts with '\0' it returns true regardless of charIs().
*/

bool strIsAll(const char* str, int (*charIs)(int));

/*************************/
/*** memory allocation ***/
/*************************/

/*
Returns a newly allocated copy of str, which must be freed by the caller.
If malloc fails, or str is null, null is returned.
*/

char* stralloc(const char* str);


#endif
