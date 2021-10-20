#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutils.h"

/**
 * A quick and dirty implementation of bucket sort.
 *
 */

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

# define MAX_VAL 2048
# define CHARNUM 8
# define TOTAL 729

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

void printStrs(char * vals[], int n);
void printInts(int vals[], int n);
void insert_bucket (char *strings[], int first, int second, int p);
void insertion_sort_bucket (char *strings[], int first, int second, int len);

/**
 * Sort vals, of size n, using bucket sort.
 */
void
bucket_sort(char * vals[], int n) {
    // strs is a 3d array
    // axis 1: the first character of the string ['a' - 'z']
    // axis 2: the second character of the string ['a' - 'z'] 
    //    and a null to consider the string with length 1, put them in bocket 0
    // axis 3: the strings that falls into bucket.
    char * strs[n][27][27];
    int sizeArr[27][27];
    // sizeArr is an array storing the size of strs for each bucket
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            sizeArr[i][j] = 0;
        }
    } // initializing size to zero
    for (int i = 0; i < n; i++) {
        // first check if the length of string is 0
        if (ithchar(vals[i], 0) == '\0'){
            strs[sizeArr[0][0]++][0][0] = vals[i];
        }
        // second check if the length of string is 1
        if (ithchar(vals[i], 1) == '\0'){
            int first = ithchar(vals[i], 0) - 'a' + 1;
            //printf("Single char found %c\n", first + 'a' - 1);
            strs[sizeArr[first][0]++][first][0] = vals[i];
        } else {
            // Put strings into correct buckets based on the first and second letters
            int first = ithchar(vals[i], 0) - 'a' + 1;
            int second = ithchar(vals[i], 1) - 'a' + 1;
            //printf("Putting string %s at first %d and second %d\n", vals[i], first, second);
            strs[sizeArr[first][second] ++] [first][second]= vals[i];
        }
    } // for assigning elements into buckets

    // do some sort in each bucket !!
    for (int first = 1; first < 27; first++) {
        for (int second = 0; second < 27; second++) {
            insertion_sort_bucket(strs[0][0], first, second, sizeArr[first][second]);
        } // for
    }
    
    // Shove them back in vals in the correct order
    int i = 0;
    for (int first = 0; first < 27; first++) {
        for (int second = 0; second < 27; second++) {
            for (int id = 0; id < sizeArr[first][second]; id++){
                vals[i++] = strs[id][first][second];
            } // for
        } // for
    }
    //printStrs(vals, n);
    // for (int first = 0; first < 27; first++) {
    //     printf("[");
    //     for (int second = 0; second < 27; second++) {
    //         printf("%d, ", sizeArr[first][second]);
    //     } // for
    //     printf("]\n");
    // }
} // bucket_sort()

// +--------------------+--------------------------------------------
// |  Insertion Sort    |
// +--------------------+

void
insert_bucket (char *strings[], int first, int second, int p)
{ 
  int i;
  char *str = strings[p * TOTAL + first * 27 + second];
  for (i = p-1; (i >= 0) && (strcmp (str, strings[i * TOTAL + first * 27 + second]) < 0); i--){
      strings[(i + 1) * TOTAL + first * 27 + second] = strings[i * TOTAL + first * 27 + second];
  }
  strings[(i + 1) * TOTAL + first * 27 + second] = str;
} // insert

void
insertion_sort_bucket (char *strings[], int first, int second, int len)
{
  for (int i = 1; i < len; i++) 
    {
      insert_bucket (strings, first, second, i);
    } // for
} // insertion_sort

// int
// main(int argc, char ** argv) {
//     char * vals[argc - 1];
//     for (int i = 1; i < argc; i++) {
//         vals[i - 1] = argv[i];
//     } // for
//     bucket_sort(vals, argc - 1);
//     printStrs(vals, argc - 1);
// } // main