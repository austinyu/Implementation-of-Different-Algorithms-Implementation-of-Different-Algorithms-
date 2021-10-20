/**
 * test-bucket.c
 * A quick test of recursive bucket sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "bucket-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (bucket_sort);
  return errors;
} // main
