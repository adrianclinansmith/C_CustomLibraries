//************************
// Tests.h
// Basic function testing.
//
// Adrian Clinansmith
// April 20, 2019
//************************

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/****************************/
/*** return value testing ***/
/****************************/

#define TEST_BOOL(x) printf("%s returned %s\n", #x, x ? "true" : "false")
#define TEST_SIZE_T(x) printf("%s returned %zu\n", #x, x)

/********************/
/*** print banner ***/
/********************/

// Prints title to stdin as a "banner", for example:
//
// **********
// some title
// **********
//
void printBanner(const char* title);

/****************************/
/*** running time testing ***/
/****************************/

// Saves the current time in a private global variable that is separate from stopTimer's variable.
void startTimer();

// Saves the current time in a private global variable that is separate from startTimer's variable.
void stopTimer();

// Returns the amount of time in microsecond between startTimer stopTimer.
long unsigned getTime();

/********************/
/*** file testing ***/
/********************/

// If func, func("dirnam/file", arg) is called for each file in dirname.
// Else if func is NULL, each file name in dirname is printed to stdin.
// "dirnam/file" cannot be larger than 512 characters.
// File names starting with '.' will be skipped (i.e. .hiddenfile)
// If dirname is NULL or an invalid directory, false is returned,
// otherwise true is returned
bool eachFile(const char* dirname, void (*func)(char*, void*), void* arg);







#endif /* TESTS_H */
