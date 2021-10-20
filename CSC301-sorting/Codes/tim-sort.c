/**
 * tim-sort.c
 * An implementation of tim sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+
#include <strings.h>
#include "tim-sort.h"
#include "strutils.h"
#include "insertion-sort.h"

#define SIZE 8
// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+
void
timSort_kernel (char *strings[], int len, char *scratch[])
{
  if (len < SIZE)
    {
      // do insertion sort when the size of the array is small enough
      insertion_sort(strings, len);
      return;
    }
  // Recursive case: Split into two halves, sort the halves, merge
  int halfsize = len/2;
  timSort_kernel (strings, halfsize, scratch);
  timSort_kernel (strings+halfsize, len-halfsize, scratch);
  merge (strings, 0, halfsize, len, scratch);
} // kernel

void
tim_sort (char *strings[], int len)
{
  // Allocate a scratch array
  char *scratch[len];

  // Use the kernel
  timSort_kernel (strings, len, scratch);
} // tim_sort

