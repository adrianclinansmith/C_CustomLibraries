//
//  maintest.c
//
//
//  Created by Adrian Thomas Clinansmith on 2019-04-18.
//

#include <stdio.h>
#include "Tests.h"
#include "stdio2.h"
#include "string2.h"
#include "strarr.h"

#define ONE "one"
#define TWO "two"

/*** PROTOTYPES ***/

void testString2();
void readWordsEachFile(char* filepath, void* arg);

/*** MAIN ***/

int main(int argc, const char* argv[])
{
   printBanner("string2 comparison");

   SEE("hello");
}

/*** PRIMARY FUNCTIONS ***/

void testStrarr()
{
    printBanner("TESTING strarr");

    // test readWords()
    eachFile("textfiles", readWordsEachFile, NULL);
}

/*** helper implementations ***/

void readWordsEachFile(char* filepath, void* arg)
{
   FILE* fp = fopen(filepath, "r");
   if (!fp)
   {
      printf("--- --- ---\nCoudn't open %s\n--- --- ---\n", filepath);
      return;
   }

   printf("--- --- ---\nreadWords(%s, &n)\n\n", filepath);

   size_t n;
   char** words = readWords(filepath, &n);

   if (words)
   {
      for (size_t i = 0; words[i]; i++)
      {
         printf("words[%zu]: \"%s\"\n", i, words[i]);
      }
   }
   else
   {
      printf("NULL\n");
   }
   printf("n = %zu\n", n);

   freeStrarr(words);
   fclose(fp);
}
