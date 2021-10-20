/**
 * competition.c
 * A friendly competition between sorting algorithms.
 *
 * Usage:
 *   competition [size [rounds [start]]]

 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "strutils.h"
#include "sorter.h"
#include "insertion-sort.h"
#include "recursive-merge-sort.h"
#include "tim-sort.h"
#include "radix-sort.h"
#include "bucket-sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/time.h>

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

/**
 * The default number of rounds of sorting.
 */
#define DEFAULT_ROUNDS 500

// +-------+---------------------------------------------------------
// | Types |
// +-------+

struct sorting_algorithm
{
  char *name;
  string_sorter sort;
};

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Build a random string.  The client is responsible for freeing
 * this string.
 */
char *
random_string()
{
  char *str = malloc(8 * sizeof(char));
  for (int i = 0; i < 7; i++)
  {
    str[i] = 'a' + abs((int)random() % 26);
  } // for
  str[7] = 0;
  return str;
} // random_string ()

// +------+----------------------------------------------------------
// | Main |
// +------+

int main(int argc, char *argv[])
{
  // Prepare our list of sorting algorithms
  struct sorting_algorithm sorts[] =
      {
          {"insertionSort", insertion_sort},
          {"recMergeSort", recursive_merge_sort},
          {"timSort", tim_sort},
          {"radixSort", radix_sort},
          {"bucketSort", bucket_sort}};

  int sizes[] = {2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000};
  int sizesLen = 8;

  // Determine the number of competitor
  int competitors = sizeof(sorts) / sizeof(struct sorting_algorithm);


  // Determine the number of rounds
  int rounds = DEFAULT_ROUNDS;

  // write runtime of each sorting algorithms in to separate csv files
  for (int i = 0; i < competitors; i++)
  {
    char *fName = (char *)malloc((strlen(sorts[i].name) + 1 + 16) * sizeof(char));
    sprintf(fName, "competition-%s.csv", sorts[i].name);
    FILE *fp = fopen(fName, "w+");

    for (int sizen = 0; sizen < sizesLen; sizen++)
    {
      int size = sizes[sizen];
      fprintf(fp, "%d,", size);
      for (int round = 0; round < rounds; round++)
      {
        // Set up our original array
        char *original[size];
        char *strings[size];
        // Fill the array
        for (int i = 0; i < size; i++)
        {
          original[i] = random_string();
        } // for
        bcopy(original, strings, size * sizeof(char *));
        struct timeval start;
        struct timeval finish;
        gettimeofday(&start, NULL);
        (sorts[i].sort)(strings, size);
        gettimeofday(&finish, NULL);
        long elapsed = (finish.tv_sec - start.tv_sec) * 1000000 + (finish.tv_usec - start.tv_usec);
        fprintf(fp, "%ld ,", elapsed);
        // Clean up after ourselves
        for (int i = 0; i < size; i++)
        {
          free(original[i]);
        } // for
      }   // for round
      fprintf(fp, "\n");
    } // for different size of arrays

    fclose(fp);
  } // for different sorting algs 

  // And we're done.
  return 0;
} // main
