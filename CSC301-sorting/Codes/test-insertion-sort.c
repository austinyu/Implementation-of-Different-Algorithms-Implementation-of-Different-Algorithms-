/**
 * test-insertion-sort.c
 * A quick test of insertion sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <strings.h>
#include "insertion-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (insertion_sort);
  return errors;
} // main
