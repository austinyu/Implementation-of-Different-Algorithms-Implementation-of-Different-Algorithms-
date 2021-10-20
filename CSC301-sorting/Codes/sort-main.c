/**
 * sort-main.c
 * Not quite the main function for a sorter.  Enough that
 * you can make your main something like the example below.
 */

// +---------+-------------------------------------------------------
// | Example |
// +---------+

/*

#include "sorter.h"
int 
main(int argc, char *argv[])
{
  return sort_main (insertion_sort, argc, argv);
} // main

*/

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include "sorter.h"

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+

int
sort_main (string_sorter sort, int argc, char *argv[])
{
  (*sort) (argv+1, argc-1);
  for (int i = 1; i < argc; i++) 
    {
      printf ("%3d: %s\n", i-1, argv[i]);
    } // for
  return 0;
} // sort_main
