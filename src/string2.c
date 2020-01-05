//************************************
// string2.c
// Extends basic string functionality.
//
// Adrian Clinansmith
// April 20, 2019
//************************************

#include "string2.h"
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

/******************/
/*** comparison ***/
/******************/

bool endsInsensitive(const char *str, const char *subStr)
{
   if (!str || !subStr)
   {
      return !str && !subStr;
   }

   int i = strlen(str)-1;
   int j = strlen(subStr)-1;

   while (i >= 0 && j >= 0)
   {
      if (tolower(str[i]) != tolower(subStr[j]))
      {
         break;
      }
      i--;
      j--;
   }
   return j < 0;
}

bool endsWith(const char* str, const char* subStr)
{
   if (!str || !subStr)
   {
      return !str && !subStr;
   }

   int i = strlen(str)-1;
   int j = strlen(subStr)-1;

   while (i >= 0 && j >= 0)
   {
     if (str[i] != subStr[j])
     {
        break;
     }
     i--;
     j--;
   }
   return j < 0;
}

bool equals(const char* str1, const char* str2)
{
   if (!str1 || !str2)
   {
      return !str1 && !str2;
   }
   return !strcmp(str1, str2);
}

bool equalsInsensitive(const char* str1, const char* str2)
{
   if (!str1 || !str2)
   {
      return !str1 && !str2;
   }

   while (*str1 && *str2)
   {
      if (tolower(*str1) != tolower(*str2))
      {
         break;
      }
      str1++;
      str2++;
   }
   return !*str1 && !*str2;
}

bool startsInsensitive(const char *str, const char *subStr)
{
   if (!str || !subStr)
   {
      return !str && !subStr;
   }

   size_t i;

   for (i = 0; subStr[i]; i++)
   {
      if (tolower(str[i]) != tolower(subStr[i]))
      {
         break;
      }
   }
   return (i && !subStr[i]) || (!str[0] && !subStr[0]);
}

bool startsWith(const char* str, const char* subStr)
{
   if (!str || !subStr)
   {
      return !str && !subStr;
   }

   size_t i;

   for (i = 0; subStr[i]; i++)
   {
      if (str[i] != subStr[i])
      {
         break;
      }
   }
   return (i && !subStr[i]) || (!str[0] && !subStr[0]);
}

/*********************/
/*** concatenation ***/
/*********************/

int snprintcat(char* str, size_t n, const char* format, ...)
{
   char* strEnd = strchr(str, '\0');

   va_list args;
   int charsWritten;

   va_start(args, format);
   charsWritten = vsnprintf(strEnd, n, format, args);
   va_end(args);

   return charsWritten;
}

int sprintcat(char* str, const char* format, ...)
{
   char* strEnd = strchr(str, '\0');

   va_list args;
   int charsWritten;

   va_start(args, format);
   charsWritten = vsprintf(strEnd, format, args);
   va_end(args);

   return charsWritten;
}

/***************/
/*** copying ***/
/***************/

size_t cpyUntil(char* dest, const char* src, const char* until)
{
   char* ptr = strstr(src, until);
   if (!ptr) { return 0; }

   size_t cpylen = ptr - src;

   strncpy(dest, src, cpylen);
   dest[cpylen] = '\0';
   return cpylen;
}

/******************/
/*** inspection ***/
/******************/

bool allDigits(const char *str)
{
   return strIsAll(str, isdigit);
}

bool allSpace(const char *str)
{
   return strIsAll(str, isspace);
}

int indexOfChar(const char* str, char c)
{
   int i;
   for (i = 0; str[i]; i++)
   {
      if (str[i] == c) { return i; }
   }
   return -1;
}

bool nullOrSpace(const char* str)
{
   return str ? allSpace(str) : true;
}

bool strIsAll(const char* str, int (*charIs)(int))
{
   for (int i = 0; str[i]; i++)
   {
      if (!charIs(str[i])) return false;
   }
   return true;
}

















// eof
