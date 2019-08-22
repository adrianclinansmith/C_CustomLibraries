//
//  strarr.c
//
//
//  Created by Adrian Thomas Clinansmith on 2019-04-20.
//

#include "strarr.h"

/*********************************/
/*** private helper prototypes ***/
/*********************************/

FILE* openAndGetMetadata(const char* filepath, size_t* numWords, size_t* maxLength);

/******************************/
/*** public implementations ***/
/******************************/

char** readWords(const char* filepath, size_t *numWords)
{
   size_t numWordsRead, maxWordLength;
   if (numWords) *numWords = 0;

   FILE* fp = openAndGetMetadata(filepath, &numWordsRead, &maxWordLength);
   if (!fp) return NULL;

   char** words = malloc(sizeof(char*)*(numWordsRead + 1));
   if (!words)
   {
      fclose(fp);
      return NULL;
   }
   words[0] = NULL;

   char* buffer = malloc(maxWordLength + 1);
   if (!buffer)
   {
      free(words);
      fclose(fp);
      return NULL;
   }

   size_t i = 0;

   while (fscanf(fp, "%s", buffer) == 1)
   {
      words[i] = malloc(strlen(buffer)+1);
      if (!words[i])
      {
         freeStrarr(words);
         words = NULL;
         numWordsRead = 0;
         break;
      }

      strcpy(words[i], buffer);
      words[++i] = NULL;
   }

   if (numWords) *numWords = numWordsRead;

   free(buffer);
   fclose(fp);
   return words;
}

bool arrHasStr(const char** arr, const char* str)
{
   for (size_t i = 0; arr[i]; i++)
   {
      if (!strcmp(arr[i], str))
      {
         return true;
      }
   }
   return false;
}

size_t appendStrarr(char** dest, const char** src)
{
   size_t i = strarrSize((const char **)dest);

   for (size_t j = 0; src[j]; j++)
   {
      dest[i++] = (char*)src[j];
   }
   dest[i] = NULL;
   return i;
}

size_t strarrSize(const char** arr)
{
   size_t i = 0;
   while (arr[i]) i++;
   return i;
}

void freeStrarr(char** strarr)
{
   if (strarr)
   {
      for (size_t i = 0; strarr[i]; i++)
      {
         free(strarr[i]);
      }
      free(strarr);
   }
}


/*** private helper implementations ***/

FILE* openAndGetMetadata(const char* filepath, size_t* numWords, size_t* maxLength)
{
   if (!filepath) return NULL;

   FILE* fp = fopen(filepath, "r");
   if (!fp) return NULL;

   size_t numWordsRead = 0;
   size_t maxLengthRead = 0;
   int c;

   while ((c = fgetc(fp)) != EOF)
   {
      if (isspace(c)) continue;

      numWordsRead++;
      size_t currentLength = 1;
      while ((c = fgetc(fp)) != EOF && !isspace(c))
      {
         currentLength++;
      }

      if (currentLength > maxLengthRead)
      {
         maxLengthRead = currentLength;
      }
   }

   if (numWords)  *numWords = numWordsRead;
   if (maxLength) *maxLength = maxLengthRead;
   fseek(fp, 0, SEEK_SET);

   return fp;
}
