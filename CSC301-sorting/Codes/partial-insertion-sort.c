/**
 * insertion-sort.c
 * An implementation of insertion sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <strings.h>
#include "partial-insertion-sort.h"
#include "strutils.h"

// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+

/**
 * insert the value at position p into the subarray at positions
 * [0 .. p-1].
 */
void
partial_insert (char *strings[], int start, int p)
{ 
  int i;
  char *str = strings[p];
  for (i = p-1; (i >= start) && (strcmp (str, strings[i]) < 0); i--)
    strings[i+1] = strings[i];
  strings[i+1] = str;
} // insert

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+

void
partial_insertion_sort (char *strings[], int start, int len)
{
  for (int i = start + 1; i < len; i++) 
    {
      partial_insert (strings, start, i);
    } // for
} // insertion_sort

