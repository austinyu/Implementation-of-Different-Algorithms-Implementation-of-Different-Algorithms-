#ifndef _BUCKET_H_
#define _BUCKET_H_

/**
 * Really simple buckets (e.g., for bucket sort)
 */

// +-------+---------------------------------------------------------
// | Types |
// +-------+

struct bucket 
  {
    char **elements;
    int capacity;
    int size;
  };

// +-----------+-----------------------------------------------------
// | Functions |
// +-----------+

/**
 * Initialize a bucket.  Returns 1 on success and 0 on
 * failure.
 */
int bucket_init (struct bucket *bucket);

/**
 * Add an element to the end of the bucket.  Returns 1 on
 * success and 0 on failure.
 */
int bucket_append (struct bucket *bucket, char *str);

#endif // _BUCKET_H_
