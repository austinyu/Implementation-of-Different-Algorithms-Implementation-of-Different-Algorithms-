#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutils.h"

/**
 * A quick and dirty implementation of radix sort.
 *
 * Sam Rebelsky
 * And the Students of CSC-301-02 2021Fa
 */

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

#define MAX_VAL 2048
# define CHARNUM 8

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * return the last character of a string and convert it to index between [0,26)
 */
// int lastChar(char* str){
//   if (ithchar(str, 0) == '\0') return '\0';
//   char prev = ithchar(str, 0) - 'a';
//   int id = 1;
//   while(ithchar(str, id) != '\0'){
//     prev = ithchar(str, id);
//     id++;
//   }
//   return prev - 'a';
// }

void printStrs(char* vals[], int n);

/**
 * Sort vals, of size n, using radix sort.
 */
void
radix_sort(char* vals[], int n) {
  // strs is a 2d array, each row represents strings with 
  // certain letter at some position 
  char * strs[27][n];
  int sizeArr[27];
  // sizeArr is an array storing the size of strs for each letter
  for (int i = 0; i < 27; i++) {
    sizeArr[i] = 0;
  }
  for (int k = CHARNUM - 1; k >= 0; k--) {
    // Clear out the size array
    for (int i = 0; i < 27; i++) {
      sizeArr[i] = 0;
    } // for
    // For each string in vals
    for (int i = 0; i < n; i++) {
      // Put strings into correct buckets based on the letter at k
      int alpha = ithchar(vals[i] , k) == '\0'? 0 : 
                       ithchar(vals[i] , k) - 'a' + 1;
      strs[alpha][sizeArr[alpha] ++] = vals[i];
      //printf("at k = %d, and putting character %c in string %s\n", k, alpha + 'a', vals[i]);
    } // for
    // Shove them back in vals in the correct order
    int i = 0;
    for (int letter = 0; letter < 27; letter ++){
      for (int id = 0; id < sizeArr[letter]; id++){
        // put strings back from left to right, up to down 
        vals[i++] = strs[letter][id];
      } // for
    } // for
    //printStrs(vals, n);
  } // for
} // radixSort

// void
// printInts(int vals[], inxt n) 
// {
//   printf ("{ %d", vals[0]);
//   for (int i = 1; i < n; i++) {
//     printf (", %d", vals[i]);
//   } // for
//   printf (" }\n");
// } // printInts

// void
// printStrs(char* vals[], int n) {
//   printf("{ %s", vals[0]);
//   for (int i = 1; i < n; i++) {
//     printf(", %s", vals[i]);
//   } // for
//   printf(" }\n");
// } // printInts

// int
// main(int argc, char ** argv) {
//   char* vals[argc - 1];
//   for (int i = 1; i < argc; i++) {
//     vals[i - 1] = argv[i];
//   } // for
//   radix_sort(vals, argc - 1);
//   printStrs(vals, argc - 1);
// } // main


