/**
 * kth-tests.c
 *   A bunch of randomized tests of the kth procedure
 * Samuel A. Rebelsky
 * CSC-301-02 2021Fa
 */

#include "kth-core.h"
#include "strutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// The largest array we'll use
#define MAX_SIZE 34

// The number of loops we do for each size
#ifndef LOOPS
#define LOOPS 10 
#endif

int
main (int argc, char *argv[])
{
  // Our count of errors
  int errors = 0;

  // Our count of tests
  int tests = 0;

  // Prepare to randomize
  srandomdev();

  // A bunch of strings in alphabetical order
  char *sorted[] = { "a0", "a1",
                     "b0", "b1",
                     "c0", "c1",
                     "d0", "d1",
                     "e0", "e1",
                     "f0", "f1",
                     "g0", "g1",
                     "h0", "h1",
                     "i0", "i1",
                     "j0", "j1",
                     "k0", "k1",
                     "l0", "l1",
                     "m0", "m1",
                     "n0", "n1",
                     "o0", "o1",
                     "p0", "p1",
                     "q0", "q1",
                     "r0", "r1",
                     "s0", "s1",
                     "t0", "t1",
                     "u0", "u1",
                     "v0", "v1",
                     "w0", "w1",
                     "x0", "x1",
                     "y0", "y1",
                     "z0", "z1",
                   };

   // The array we'll actually be searching; a permuted perm of
   // some subset of the origional.
   char *perm[MAX_SIZE];

   // A temporary copy of that, so that we can maintain that original.
   char *strs[MAX_SIZE];

   // Try every array size from 1 to MAX_SIZE (kth is pointless in arrays
   // of size 0).
   for (int size = 1; size <= MAX_SIZE; size++)
     {
       for (int loop = 0; loop < LOOPS; loop++)
         {
           // Set up the array in sorted order
           for (int i = 0; i < size; i++)
             {
               perm[i] = sorted[i];
             }

           // Permute the array
           for (int j = 0; j < size; j++) 
             {
               swap (random() % size, random() % size, perm);
             } // for j

           // For each k
           for (int k = 0; k < size; k++)
             {
               // Make a copy of the permuted array
               for (int i = 0; i < size; i++) 
                 {
                   strs[i] = perm[i];
                 } // for
    
               // Verify that the kth element is correct 
               ++tests;
               char *result = kth (k, strs, size);
               if (strcmp (result, sorted[k]) != 0)
                 {
                   fprintf (stderr, "kth (%d, ", k);
                   fprintstrings (stderr, perm, size);
                   fprintf (stderr, 
                            ", %d) produced \"%s\" instead of \"%s\"\n",
                            size, result, sorted[k]);
                   ++errors;
                 } // if they don't match
             } // for k
         } // for loop
     } // for size

  fprintf (stderr, "%d of %d tests failed.\n", errors, tests);
  fprintf (stderr, "%ld swaps.\n", swaps);
  return errors;
} // main
