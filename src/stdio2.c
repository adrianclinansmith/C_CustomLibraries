/*
stdio2.c
Extends basic input/output functionality.

Adrian Clinansmith
August 16, 2019
*/

#include "stdio2.h"

int getto(char** strp, size_t* num, char* to, size_t tosize, FILE* fp)
{
   if (!strp || !num || !fp) return -1;

   const int INC = *num ? *num : 100;
   int c, i = 0, j = 0;

   while ((c = getc(fp)) != EOF)
   {
      if (!((i+1) % INC)|| !*num || !*strp)
      {
         char* temp = realloc(*num ? *strp : NULL, *num + INC);

         if (!temp)
         {
            if (*strp && *num) free(*strp);
            return -1;
         }
         *num += INC;
         *strp = temp;
      }

      (*strp)[i]   = c;
      (*strp)[++i] = '\0';

      if (!to || !tosize) continue;

      j = (c == to[j]) ? j+1 : 0;
      if (j >= tosize) break;
   }

   return i;
}

int fgetsto(char* str, size_t num, char* to, size_t tosize, FILE* fp)
{
   if (!str || !fp) return -1;

   int c, i = 0, j = 0;

   while ((!num || i < num) && (c = getc(fp)) != EOF)
   {
      str[i]   = c;
      str[++i] = '\0';

      if (!to || !tosize) continue;

      j = (c == to[j]) ? j+1 : 0;
      if (j >= tosize) break;
   }

   return i;
}
