/**
 * simple-bucket-sort.c
 * A simplified bucket sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdlib.h>
#include "simple-bucket-sort.h"
#include "recursive-merge-sort.h"
#include "strutils.h"
#include "bucket.h"

// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+

void
simple_bucket_sort (char *strings[], int len)
{
  // Set up our buckets
  struct bucket buckets[5];
  for (int i = 0; i < 5; i++)
    bucket_init (&(buckets[i]));

  // Shove strings into buckets
  for (int i = 0; i < len; i++)
    {
      char *str = strings[i];
      char ch = str[0];
      if (ch <= 'e')
        bucket_append (&(buckets[0]), str);
      else if (ch <= 'j')
        bucket_append (&(buckets[1]), str);
      else if (ch <= 'o')
        bucket_append (&(buckets[2]), str);
      else if (ch <= 't')
        bucket_append (&(buckets[3]), str);
      else
        bucket_append (&(buckets[4]), str);
    } // for i

  // Sort the buckets
  for (int i = 0; i < 5; i++)
    {
      recursive_merge_sort (buckets[i].elements, buckets[i].size);
    } // for

  // Shove them back into the original array.
  int p = 0;    // Index into original array
  for (int i = 0; i < 5; i++)
    {
      char **elements = buckets[i].elements;
      int size = buckets[i].size;
      for (int j = 0; j < size; j++)
        {
          strings[p++] = elements[j];
        } // for j
    } // for i

  // Clean up
  for (int i = 0; i < 5; i++)
    {
      free (buckets[i].elements);
    } // for
} // simple_bucket_sort

