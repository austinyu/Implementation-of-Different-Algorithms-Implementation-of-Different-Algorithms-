#ifndef _SORTER_H_
#define _SORTER_H_

/**
 * sorter.h
 * Declarations for things that sort.
 */

// +-------+---------------------------------------------------------
// | Types |
// +-------+

/**
 * Procedures that sort arrays of strings.
 */
typedef void (*string_sorter)(char *strings[], int len);

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

/**
 * Run a bunch of tests on a sorter.  Returns the number of
 * errors encountered.  Also prints out sorting issues as 
 * it goes.
 */
int test_sorter(string_sorter sort);

/**
 * An equivalent of main.
 */
int sort_main(string_sorter sort, int argc, char *argv[]);

#endif // _SORTER_H_
