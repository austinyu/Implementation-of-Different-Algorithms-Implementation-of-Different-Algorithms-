/**
 * sort-tester.c
 * Tests for things that sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutils.h"
#include "sorter.h"

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

/** 
 * The number of permutations of each size we try.
 */
#define PERMS 8

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Determine if two arrays of strings are different.
 */
int
different (char *this[], char *that[], int n)
{
  for (int i = 0; i < n; i++)
    {
      if (this[i] != that[i])
        {
          return 1;
        } // if
    } // for i
  return 0;
} // different

// +---------------------+-------------------------------------------
// | Exported Procedures |
// +---------------------+

int
test_sorter (string_sorter sort)
{
  int errors = 0;       // The number of errors we've encountered.
  int tests = 0;        // The number of tests we've conducted.
  char *sorted[] =      // Our sorted array, used to generate all tests.
    { "a", "a", "aa", "ab",
      "b", "b", "ba", "baa", "baa",
      "c", "c", "c", "c",
      "da", "db", "dc", "dd",
      "e", "ee", "eee", "eeee", "eeeee"
      "f", "f", "f",
      "g", "g", "g",
      "h",
      "i",
      "j",
      "k",
      "l", "l", "la", "le", "li", "lo", "lu",
      "m", "m", "m", "m", "m", "m", "m", "m"
      "n",
      "o",
      "p",
      "q",
      "r",
      "s",
      "t",
      "u"
    };
  int len = sizeof (sorted) / sizeof (char *);
                        // The length of our sorted array.
  char *permuted[len];  // A permuted copy of our sorted array.
  char *strings[len];   // The copy we actually sort.

  srandomdev();

  for (int n = 0; n <= len; n++)
    {
      for (int i = 0; i < PERMS; i++) 
        {
          bcopy (sorted, permuted, sizeof (char *) * n);
          permute (permuted, n);
          bcopy (permuted, strings, sizeof (char *) * n);

#ifdef TRACE
          fprintf (stderr, "Sorting: ");
          fprintstrings (stderr, strings, n);
          fprintf (stderr, "\n");
#endif

          ++tests;
          (*sort) (strings, n);

#ifdef TRACE
          fprintf (stderr, "Sorted:  ");
          fprintstrings (stderr, strings, n);
          fprintf (stderr, "\n");
#endif

          if (different (sorted, strings, n))
            {
              fprintf (stderr, "Failed to sort correctly: ");
              fprintstrings (stderr, permuted, n);
              fprintf (stderr, "\n");
              fprintf (stderr, "Result: ");
              fprintstrings (stderr, strings, n);
              fprintf (stderr, "\n");
              ++errors;
            } // if different
        } // for i
    } // for n
  fprintf (stderr, "Passed %d of %d tests.\n", tests-errors, tests);
  return errors;
} // test_sorter
