/**
 * test-sbs.c
 * A quick test of simple bucket sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "simple-bucket-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (simple_bucket_sort);
  return errors;
} // main
