/**
 * recursive-merge-sort.c
 * An implementation of recursive merge sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <strings.h>
#include "recursive-merge-sort.h"
#include "strutils.h"

// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+

void
rms_kernel (char *strings[], int len, char *scratch[])
{
  // Base case: Zero or one elements are already sorted.
  if (len < 2)
    {
      return;
    }

  // Recursive case: Split into two halves, sort the halves, merge
  int halfsize = len/2;
  rms_kernel (strings, halfsize, scratch);
  rms_kernel (strings+halfsize, len-halfsize, scratch);
  merge (strings, 0, halfsize, len, scratch);
} // kernel

void
recursive_merge_sort (char *strings[], int len)
{
  // Allocate a scratch array
  char *scratch[len];

  // Use the kernel
  rms_kernel (strings, len, scratch);
} // recursive-merge_sort

