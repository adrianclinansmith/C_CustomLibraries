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
   TEST_BOOL(endsInsensitive("one", "one"));
   TEST_BOOL(endsInsensitive("redrum", "RUM"));
   TEST_BOOL(endsInsensitive("RUM", "redrum"));
   TEST_BOOL(endsInsensitive("redrum", ""));
   TEST_BOOL(endsInsensitive("", "RUM"));
   TEST_BOOL(endsInsensitive("redrum", NULL));
   TEST_BOOL(endsInsensitive(NULL, "RUM"));
   TEST_BOOL(endsInsensitive(NULL, NULL));
   putchar('\n');

   TEST_BOOL(endsWith("one", "one"));
   TEST_BOOL(endsWith("redrum", "rum"));
   TEST_BOOL(endsWith("rum", "redrum"));
   TEST_BOOL(endsWith("redrum", ""));
   TEST_BOOL(endsWith("", "rum"));
   TEST_BOOL(endsWith("redrum", NULL));
   TEST_BOOL(endsWith(NULL, "rum"));
   TEST_BOOL(endsWith(NULL, NULL));
   putchar('\n');

   TEST_BOOL(equals("one", "two"));
   TEST_BOOL(equals("one", "one"));
   TEST_BOOL(equals("one", ""));
   TEST_BOOL(equals("one", NULL));
   TEST_BOOL(equals(NULL, "two"));
   TEST_BOOL(equals(NULL, NULL));
   putchar('\n');

   TEST_BOOL(equalsInsensitive("one", "two"));
   TEST_BOOL(equalsInsensitive("one", "ONE"));
   TEST_BOOL(equalsInsensitive("one", ""));
   TEST_BOOL(equalsInsensitive("one", NULL));
   TEST_BOOL(equalsInsensitive(NULL, "two"));
   TEST_BOOL(equalsInsensitive(NULL, NULL));
   putchar('\n');

   TEST_BOOL(startsInsensitive("one", "one"));
   TEST_BOOL(startsInsensitive("redrum", "RED"));
   TEST_BOOL(startsInsensitive("RED", "redrum"));
   TEST_BOOL(startsInsensitive("redrum", ""));
   TEST_BOOL(startsInsensitive("", "RED"));
   TEST_BOOL(startsInsensitive("redrum", NULL));
   TEST_BOOL(startsInsensitive(NULL, "RED"));
   TEST_BOOL(startsInsensitive(NULL, NULL));
   putchar('\n');

   TEST_BOOL(startsWith("one", "one"));
   TEST_BOOL(startsWith("redrum", "red"));
   TEST_BOOL(startsWith("red", "redrum"));
   TEST_BOOL(startsWith("redrum", ""));
   TEST_BOOL(startsWith("", "red"));
   TEST_BOOL(startsWith("redrum", NULL));
   TEST_BOOL(startsWith(NULL, "red"));
   TEST_BOOL(startsWith(NULL, NULL));
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
