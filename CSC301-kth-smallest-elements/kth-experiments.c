#include "kth-core.h"
#include "strutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <strings.h>

// The largest array we'll use
#define MAX_SIZE 50

// The number of loops we do for each size
#ifndef LOOPS
#define LOOPS 100
#endif

void resetSwaps();

int main(int argc, char *argv[])
{
    // Our count of errors
    int errors = 0;
    // Our count of tests
    int tests = 0;
    // Prepare to randomize
    srandomdev();
    FILE *file;
    file = fopen("kth-experiment.csv", "w+");
    fprintf (file, "%s\n", "size ,k, min, max, average");
    // A bunch of strings in alphabetical order
    char *sorted[] = {"a0", "a1", "b0", "b1", "c0", "c1", 
        "d0", "d1", "e0", "e1", "f0", "f1", "g0", "g1",
        "h0","h1", "i0", "i1", "j0", "j1", "k0", "k1",
        "l0", "l1", "m0", "m1", "n0", "n1", "o0", "o1",
        "p0", "p1", "q0", "q1", "r0", "r1", "s0", "s1", 
        "t0", "t1", "u0", "u1", "v0", "v1", "w0", "w1",
        "x0", "x1", "y0", "y1", "z0", "z1",
    };

    // The array we'll actually be searching; a permuted perm of
    // some subset of the origional.
    char *perm[MAX_SIZE];


    // Try every array size from 1 to MAX_SIZE (kth is pointless in arrays
    // of size 0).
    for (int size = 1; size <= MAX_SIZE; size++)
    {
        for (int k = 0; k < size; k++)
        {
            fprintf(file, "%d, ", size);
            fprintf(file, "%d, ", k);
            long minloop = 2147483647, maxloop = 0, total = 0;
            int iter = 1;

            for (int loop = 1; loop < LOOPS; loop++)
            {
                for (int i = 0; i < size; i++)
                {
                perm[i] = sorted[i];
                }
                // Permute the array
                for (int j = 0; j < size; j++)
                {
                swap(random() % size, random() % size, perm);
                } // for j
                
                char *result = kth(k, perm, size);
                minloop = swaps < minloop? swaps : minloop;
                maxloop = swaps > maxloop? swaps : maxloop;
                total += swaps;
                iter ++;
                resetSwaps();
            } // for loop
            fprintf(file, "%ld, ", minloop);
            fprintf(file, "%ld, ", maxloop);
            fprintf(file, "%ld \n", total / iter);
        }     // for k

    }         // for size
    fclose (file);
    return errors;
} // main

