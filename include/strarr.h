/*
strarr.h
Functions for working with arrays of strings. An array of strings must be
terminated with a NULL pointer.

Adrian Clinansmith
April 20, 2019
*/

#ifndef STRARR_H
#define STRARR_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Reads all words from the file at 'filepath' and returns them in an array of
strings. A word is a string of non-space characters (!isspace(c)). If 'numWords'
is not NULL, it will hold the number of words read. If 'filepath' is not a valid
file, or memory could not be allocated, then NULL will be returned and
'numWords' will store 0. The strings and pointers returned must be freed by the
user program, typically using freeStrarr().
*/

char** readWords(const char* filepath, size_t *numWords);

/*
Returns true if str is found in 'arr', false otherwise.
*/

bool arrHasStr(const char** arr, const char* str);

/*
Appends all the strings in 'src' to the end of 'dest'. 'dest' must be large
enough to hold the additional strings.
*/

size_t appendStrarr(char** dest, const char** src);

/*
Returns the number of strings in 'arr'.
*/

size_t strarrSize(const char** arr);

/*
Frees all the strings and pointers that make up 'strarr'. If 'strarr' is NULL
the function simply returns.
*/

void freeStrarr(char** strarr);


#endif /* STRARR_H */
