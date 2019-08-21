/*
stdio2.h
Extends basic input/output functionality.

Adrian Clinansmith
August 16, 2019
*/

#ifndef STDIO2_H
#define STDIO2_H

#include <stdio.h>
#include <stdlib.h>

/*
Reads chars from 'fp' and stores them in 'str' until 'num'-1 chars have been
read or either 'to' or EOF is reached, whichever happens first. The length of
'to' is determined by 'tosize' rather than a terminating NULL, therefore NULLs
can be read from 'fp'. If 'to' is found, it is included in 'str'. Regardless, a
NULL char is always appended to the end of 'str' after all other chars are
copied.

If 'num' is 0, there is no limit on the number of chars that can be read.
If 'to' is NULL and/or 'tosize' is 0, chars will be read until 'num'-1 or EOF.

On success, the number of chars read from 'fp' is returned. If 'fp' or 'str' is
NULL, no chars are read and -1 is returned.
*/

int fgetsto(char* str, size_t num, char* to, size_t tosize, FILE* fp);

/*
Reads chars from 'fp' and stores the address of the buffer containing the text
into '*strp' until 'to' or EOF is reached, whichever happens first. The length
of 'to' is determined by 'tosize' rather than a terminating NULL, therefore
NULLs can be read from 'fp'. If 'to' is found, it is included in '*strp'.
Regardless, a terminating NULL is always appended to the end of '*strp' after
all other chars are copied.

If '*strp' is NULL and/or '*num' is 0 then a buffer will be allocated and must
be freed by the user program. If '*strp' is NULL and '*num' is non-zero then the
buffer will be initially allocated with size '*num', and more will be allocated
if it is not enough.

Alternatively, before calling getto(), '*strp' can contain a pointer to an
allocated buffer '*num' bytes in size. If the initial buffer size is not enough,
more will be allocated.

In either case, on a successful call, '*strp' and '*num' are updated to reflect
the buffer address and allocated size respectively.

On success, the number of chars read is returned. The terminating NULL is not
included. If 'strp', 'num', of 'fp' is NULL, or if memory allocation failed, -1
is returned and no memory needs to be freed by the user program.
*/

int getto(char** strp, size_t* num, char* to, size_t tosize, FILE* fp);

#endif
