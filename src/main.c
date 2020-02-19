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



/*** PROTOTYPES ***/

void testString2();
void readWordsEachFile(char* filepath, void* arg);

/*** MAIN ***/

int main(int argc, const char* argv[])
{
   printBanner("string2 comparison");


   SEEFREE_STR(stralloc("hello"));
   SEEFREE_STR(stralloc(""));
   SEEFREE_STR(stralloc(NULL));


   char testStrs[2][5] = { "one", "two" };
   SEE_PRIM(endsInsensitive(testStrs[1], testStrs[2]));
   SEE_PRIM(endsInsensitive("one", "one"));
   SEE_PRIM(endsInsensitive("redrum", "RUM"));
   SEE_PRIM(endsInsensitive("RUM", "redrum"));
   SEE_PRIM(endsInsensitive("redrum", ""));
   SEE_PRIM(endsInsensitive("", "RUM"));
   SEE_PRIM(endsInsensitive("redrum", NULL));
   SEE_PRIM(endsInsensitive(NULL, "RUM"));
   SEE_PRIM(endsInsensitive(NULL, NULL));
   putchar('\n');

   SEE_PRIM(indexOfChar("Monica", 'i'));
   SEE_PRIM(indexOfChar("Monica", 'M'));
   SEE_PRIM(indexOfChar("Monica", 'f'));
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
