/**
 * strutils.c
 * Various string utilities
 *
 * Samuel A. Rebelsky
 * CSC-301-02 2021Fa
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "strutils.h"
#include <strings.h>
#include <stdio.h>


// +--------------------+--------------------------------------------
// | Exported Variables |
// +--------------------+

long swaps = 0;

void resetSwaps(){
  swaps = 0;
}

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+


void 
fprintstrings (FILE *port, char *strs[], int n)
{
  if (n <= 0)
    printf ("{}");
  else
    {
      fprintf (port, "{ \"%s\"", strs[0]);
      for (int i = 1; i < n; i++)
        fprintf (port, ", \"%s\"", strs[i]);
      fprintf (port, " }");
    } // if (n > 0)
  fflush (port);
} // fprintstrings

void 
swap (int i, int j, char *strs[])
{
  ++swaps;
  char *tmp = strs[i];
  strs[i] = strs[j];
  strs[j] = tmp;
} // swap (int, int, char**)

