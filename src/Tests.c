//************************
// Tests.c
// Basic function testing.
//
// Adrian Clinansmith
// April 20, 2019
//************************

#include "Tests.h"
#include <sys/time.h>
#include <sys/types.h>
#include <dirent.h>

#define MILLION 1000000UL
struct timeval start_TESTS_H_, end_TESTS_H_;

/********************/
/*** print banner ***/
/********************/

void printBanner(const char* title)
{
   size_t len = strlen(title);

   printf("\n\n");
   for (size_t i = 0; i < len; i++) { putchar('*'); }
   printf("\n%s\n", title);
   for (size_t i = 0; i < len; i++) { putchar('*'); }
   printf("\n\n");
}

/****************************/
/*** running time testing ***/
/****************************/

void startTimer()
{
   gettimeofday(&start_TESTS_H_, NULL);
}

void stopTimer()
{
   gettimeofday(&start_TESTS_H_, NULL);
}

long unsigned getTime()
{
   struct timeval start = start_TESTS_H_;
   struct timeval end = end_TESTS_H_;

   // time in microseconds =
   // (end secs - start secs) x 1 million + (end microsecs - start microsecs)
   return (end.tv_sec - start.tv_sec)*MILLION + (end.tv_usec - start.tv_usec);
}

/********************/
/*** file testing ***/
/********************/

bool eachFile(const char* dirname, void (*func)(char*, void*), void* arg)
{
   DIR* dp;
   if (!dirname || !(dp = opendir(dirname))) return false;

   struct dirent* d_ent;
   const size_t MAXLEN = 512;   // 256 x 2
   char filepath[MAXLEN];

   while ((d_ent = readdir(dp)))
   {
      if (d_ent->d_name[0] == '.') continue;

      int wrote = snprintf(filepath, MAXLEN, "%s/%s", dirname, d_ent->d_name);
      if (wrote < 0) continue;

      if (func) func(filepath, arg);
      else printf("%s\n", filepath);
   }

   closedir(dp);
   return true;
}
