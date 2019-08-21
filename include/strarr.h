//
//  strarr.h
//
//
//  Created by Adrian Thomas Clinansmith on 2019-04-20.
//

#ifndef STRARR_H
#define STRARR_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// Reads all words from filepath and returns them in an array
// of strings. A word is a string of non-space characters (!isspace(c)).
// If numWords is not NULL, it will hold the number of words read.
// If filepath is not a valid file, or memory could not be allocated,
// then NULL will be returned and numWords will store 0.
char** readWords(const char* filepath, size_t *numWords);

// Returns true if str is found in arr, false otherwise.
bool arrHasStr(const char** arr, const char* str);

// Appends all the strings in src to the end of dest.
// dest must be large enough to hold the additional strings.
size_t appendStrarr(char** dest, const char** src);

// Returns the number of strings in arr.
size_t strarrSize(const char** arr);

// Frees all the strings and string pointers that make up strarr.
// If strarr is NULL the function simply returns.
void freeStrarr(char** strarr);


#endif /* STRARR_H */
