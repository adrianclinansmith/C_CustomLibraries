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

#include "tgmath.h"

/*** PROTOTYPES ***/

void testString2();
void readWordsEachFile(char* filepath, void* arg);

/*** MAIN ***/

int main(int argc, const char* argv[])
{
   printBanner("string2 comparison");

   int i = _Generic('a', char: 1, int: 2, long: 3, default: 0);
   printf("i is %d\n", i);

   SEEFREE_STR(stralloc("hello"));
   SEEFREE_STR(stralloc(""));
   SEEFREE_STR(stralloc(NULL));


   char testStrs[2][5] = { "one", "two" };
   SEE_BOOL(endsInsensitive(testStrs[1], testStrs[2]));
   // SEE_BOOL(endsInsensitive("one", "one"));
   // SEE_BOOL(endsInsensitive("redrum", "RUM"));
   // SEE_BOOL(endsInsensitive("RUM", "redrum"));
   // SEE_BOOL(endsInsensitive("redrum", ""));
   // SEE_BOOL(endsInsensitive("", "RUM"));
   // SEE_BOOL(endsInsensitive("redrum", NULL));
   // SEE_BOOL(endsInsensitive(NULL, "RUM"));
   // SEE_BOOL(endsInsensitive(NULL, NULL));
   putchar('\n');


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
