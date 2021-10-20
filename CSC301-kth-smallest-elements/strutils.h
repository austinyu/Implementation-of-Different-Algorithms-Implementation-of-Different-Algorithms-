#ifndef _STR_UTILS_
#define _STR_UTILS_

/**
 * strutils.h
 * Various string utilities.
 *
 * Samuel A. Rebelsky
 * CSC-301-02 2021Fa
 */

#include <stdio.h>

/**
 * Swap two strings in an array.  Does not check for valid indices.
 */
void swap (int i, int j, char *strs[]);

/**
 * The count of the number of swaps.  Feel free to reset to 0
 * whenever you want to start counting.
 */
extern long swaps;

/**
 * Print an array of n strings.
 */
void fprintstrings (FILE *port, char *strs[], int n);

#endif // _STR_UTILS_
