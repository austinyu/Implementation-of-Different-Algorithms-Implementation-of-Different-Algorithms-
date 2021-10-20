/**
 * test-fake.c
 * A quick test of our fake sort
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "fake-sort.h"
#include "sorter.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int errors = test_sorter (fake_sort);
  return errors;
} // main
