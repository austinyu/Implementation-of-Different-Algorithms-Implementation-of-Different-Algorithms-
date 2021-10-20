/**
 * bucket.c
 * A simple implementation of buckets.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "bucket.h"
#include <stdlib.h>

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

/**
 * The default capacity of buckets.
 */
#define DEFAULT_CAPACITY 8

// +-----------+-----------------------------------------------------
// | Functions |
// +-----------+

/**
 * Initialize a bucket.
 */
int
bucket_init (struct bucket *bucket)
{
  char **elements = (char **) malloc (DEFAULT_CAPACITY * sizeof (char *));
  if (! elements)
    return 0;

  bucket->elements = elements;
  bucket->size = 0;
  bucket->capacity = DEFAULT_CAPACITY;
  return 1;
} // bucket_init

/**
 * Add an element to the end of the bucket.
 */
int
bucket_append (struct bucket *bucket, char *str)
{
  // Expand the bucket if there's insufficient room
  if (bucket->size == bucket->capacity)
    {
      char **elements =
        (char **) realloc (bucket->elements, 
                           2 * bucket->capacity * sizeof (char *));
      if (!elements)
        return 0;
 
      bucket->elements = elements;
      bucket->capacity = 2 * bucket->capacity;
    } // if size == capacity

  // Add the element
  bucket->elements[bucket->size++] = str;
  return 0;
} // bucket_append
