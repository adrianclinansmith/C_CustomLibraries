/*
stdio2.c
Extends basic input/output functionality.

Adrian Clinansmith
August 16, 2019
*/

#include "stdio2.h"

/* helper prototypes */

void* reallocf(void* ptr, size_t n);

/* implementations */

int fgetsto(char* str, size_t num, char* to, size_t tosize, FILE* fp)
{
   if (!str || !fp) return -1;

   int c, i = 0, j = 0;

   while ((!num || i+1 < num) && (c = getc(fp)) != EOF)
   {
      str[i++] = c;

      if (!to || !tosize) continue;

      j = (c == to[j]) ? j+1 : 0;
      if (j >= tosize) break;
   }

   str[i] = '\0';
   return i;
}

int getto(char** strp, size_t* num, char* to, size_t tosize, FILE* fp)
{
   if (!strp || !num || !fp) return -1;

   const int INCR = *num ? *num : 100;

   if (!*num)  *strp = NULL;
   if (!*strp) *num  = 0;

   int c, i = 0, j = 0;

   while ((c = getc(fp)) != EOF)
   {
      if (!((i+1) % INCR) || !*strp)
      {
         *strp = reallocf(*strp, *num += INCR);
         if (!*strp) return -1;
      }

      (*strp)[i++] = c;

      if (!to || !tosize) continue;

      j = (c == to[j]) ? j+1 : 0;
      if (j >= tosize) break;
   }

   (*strp)[i] = '\0';
   return i;
}

/* helper functions */

void* reallocf(void* ptr, size_t n)
{
   void* new = realloc(ptr, n);

   if (!new && ptr) free(ptr);
   return new;
}
