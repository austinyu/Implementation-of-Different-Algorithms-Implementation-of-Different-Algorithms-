/**
 * test-rms.c
 * A quick test of recursive merge sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "recursive-merge-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (recursive_merge_sort);
  return errors;
} // main
