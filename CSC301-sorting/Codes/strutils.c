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
#include <stdlib.h>

// +--------------------+--------------------------------------------
// | Exported Variables |
// +--------------------+

long swaps = 0;

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+

void 
fprintstrings (FILE *port, char *strs[], int n)
{
  if (n <= 0)
    fprintf (port, "{ }");
  else
    {
      fprintf (port, "{ \"%s\"", strs[0]);
      for (int i = 1; i < n; i++)
        fprintf (port, ", \"%s\"", strs[i]);
      fprintf (port, " }");
    } // if (n > 0)
  fflush (port);
} // fprintstrings

char
ithchar (char *str, int i)
{
  for (int c = 0; c < i; c++)
    {
      if (! str[c]) return (char) 0;
    } // for c
  return str[i];
} // ithchar (char *, int)

void 
swap (char *strs[], int i, int j)
{
  ++swaps;
  char *tmp = strs[i];
  strs[i] = strs[j];
  strs[j] = tmp;
} // swap (int, int, char**)

/**
 * Permute the values in an array.  Perfect randomness is not
 * guaranteed.
 */
void
permute (char *strings[], int len)
{ 
  for (int i = 0; i < len; i++) 
    {
      swap (strings, rand () % len, rand () % len);
    } // for
} // permute

/**
 * Merge sorted subarrays at [lb,mid) and [mid,ub) using scratch.
 */
void 
merge (char *strings[], int lb, int mid, int ub, char *scratch[])
{
  int p1 = lb;
  int p2 = mid;
  int p = 0;

  //  lb    p1     mid    p2     ub
  //  |  A  |   B   |  C  |  D   |

  // As long as we have elements in sections B and D
  while ((p1 < mid) && (p2 < ub))
    {
      // Copy over the smaller element, biasing equal elements
      // to the left subarray.
      if (strcmp (strings[p1], strings[p2]) <= 0)
        scratch[p++] = strings[p1++];
      else
        scratch[p++] = strings[p2++];
    } // while

  // At this point
  //               p1
  //  lb           mid    p2     ub
  //  |  A          |  C  |  D   |
  // or
  //  lb    p1     mid           ub
  //  |  A  |   B   |  C         |

  // Put the remaining elements at the end of scratch
  while (p1 < mid)
    {
      scratch[p++] = strings[p1++];
    } // while
  while (p2 < ub)
    {
      scratch[p++] = strings[p2++];
    } // while

  // Copy the elements back from the scratch to the strings
  // (because this is a void procedure)
  for (int i = 0; i < p; i++)
    {
      strings[lb+i] = scratch[i];
    } // for
} // merge

void
printStrs(char * vals[], int n) {
    printf("{ %s", vals[0]);
    for (int i = 1; i < n; i++) {
        printf(", %s", vals[i]);
    } // for
    printf(" }\n");
} // printInts

void
printInts(int vals[], int n) 
{
  printf ("{ %d", vals[0]);
  for (int i = 1; i < n; i++) {
    printf (", %d", vals[i]);
  } // for
  printf (" }\n");
} // printInts