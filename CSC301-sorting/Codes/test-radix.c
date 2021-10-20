/**
 * test-bucket.c
 * A quick test of recursive bucket sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "radix-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (radix_sort);
  return errors;
} // main
