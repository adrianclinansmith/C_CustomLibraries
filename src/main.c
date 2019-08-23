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
void testStrarr();
void readWordsEachFile(char* filepath, void* arg);

/*** MAIN ***/

//int fgetsto(char* str, size_t num, char* to, size_t tosize, FILE* fp)

int main(int argc, const char* argv[])
{
   size_t num = 16;
   char* str = malloc(num);

   char* to = "hon";
   FILE* fp = fopen("textfiles/2045Words.txt", "rb");

   int n, i = 0;
   while ((n = getto(&str, &num, to, strlen(to), fp)))
   {
      printf("str:\n\"%s\"\nnum = %zu, n = %d\n", str, num, n);
      if (n < 0) printf("error\n");
      printf("i = %d\n\n", ++i);
   }

   free(str);
   fclose(fp);
   return 0;
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