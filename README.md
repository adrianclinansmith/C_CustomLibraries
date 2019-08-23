# C Custom Library
> Additional functions for standard C beyond libc (the C standard library).

## Table of Contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
This library can reduce some of the busywork common to vanilla C. Some files
directly extend libc. For example, the functions in this library's string2.h
would not seem out of place in libc's string.h. Files that extend the standard
library share a name with their associate libc header file: stdio2.h, string2.h,
etc. This library also has files that do not correspond to anything in libc such
as strarr.h. For API details, please consult the [header files](https://github.com/adrianclinansmith/C_CustomLibraries/tree/master/include).

## Technologies
Conforms to the C11 standard.

## Setup
For use in your own project, add one or more [header files](https://github.com/adrianclinansmith/C_CustomLibraries/tree/master/include) to your own C header
files, and add the corresponding [implementation files](https://github.com/adrianclinansmith/C_CustomLibraries/tree/master/src) to your C implementation
files, then compile your project as usual.