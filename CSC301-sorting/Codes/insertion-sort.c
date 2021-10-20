/**
 * insertion-sort.c
 * An implementation of insertion sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <strings.h>
#include "insertion-sort.h"
#include "strutils.h"

// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+

/**
 * insert the value at position p into the subarray at positions
 * [0 .. p-1].
 */
void
insert (char *strings[], int p)
{ 
  int i;
  char *str = strings[p];
  for (i = p-1; (i >= 0) && (strcmp (str, strings[i]) < 0); i--)
    strings[i+1] = strings[i];
  strings[i+1] = str;
} // insert

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+

void
insertion_sort (char *strings[], int len)
{
  for (int i = 1; i < len; i++) 
    {
      insert (strings, i);
    } // for
} // insertion_sort

