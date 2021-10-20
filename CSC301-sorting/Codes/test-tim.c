/**
 * test-tim.c
 * A quick test of tim sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "tim-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (tim_sort);
  return errors;
} // main
