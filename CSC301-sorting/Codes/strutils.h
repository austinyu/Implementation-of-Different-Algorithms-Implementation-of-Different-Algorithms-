#ifndef _STR_UTILS_H_
#define _STR_UTILS_H_

/**
 * strutils.h
 * Various string utilities.
 *
 * Samuel A. Rebelsky
 * CSC-301-02 2021Fa
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>

// +--------------------+--------------------------------------------
// | Exported Variables |
// +--------------------+

/**
 * The count of the number of swaps.  Feel free to reset to 0
 * whenever you want to start counting.
 */
extern long swaps;

// +--------------------+--------------------------------------------
// | Exported Functions |
// +--------------------+

/**
 * Swap two strings in an array.  Does not check for valid indices.
 */
void swap (char *strs[], int i, int j);

/**
 * Print an array of n strings.
 */
void fprintstrings (FILE *port, char *strs[], int n);

/**
 * Grab the ith character of a string.  Returns 0 if the
 * string has fewer than i characters.
 */
char ithchar (char *string, int i);

/**
 * Permute an array of strings of length n.
 */
void permute (char *strings[], int n);

/**
 * Merge the sorted subarrays at [lb,mid) and [mid,ub) using
 * a scratch array to help.
 */
void merge (char *strings[], int lb, int mid, int ub, char *scratch[]);

void printInts(int vals[], int n);

void printStrs(char * vals[], int n);

#endif // _STR_UTILS_H_
