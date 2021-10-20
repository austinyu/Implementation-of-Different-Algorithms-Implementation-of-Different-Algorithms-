/**
 * bucket-sort.c
 * A bucket sort.
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdlib.h>
#include "simple-bucket-sort.h"
#include "recursive-merge-sort.h"
#include "strutils.h"
#include "bucket.h"

// +-----------------+-----------------------------------------------
// | Local Utilities |
// +-----------------+

void
bucket_sort(char * strings[], int len) {
    // Set up our buckets
    struct bucket buckets[27][27];
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            bucket_init( & (buckets[i][j]));
        }
    }
    // Shove strings into buckets
    for (int i = 0; i < len; i++) {
        // first check if the length of string is 0
        if (ithchar(strings[i], 0) == '\0') {
            bucket_append (&(buckets[0][0]), strings[i]);
        }
        // second check if the length of string is 1
        else if (ithchar(strings[i], 1) == '\0') {
            int first = ithchar(strings[i], 0) - 'a' + 1;
            //printf("Single char found %c\n", first + 'a' - 1);
            bucket_append (&(buckets[first][0]), strings[i]);
        } else {
            // Put strings into correct buckets based on the first and second letters
            int first = ithchar(strings[i], 0) - 'a' + 1;
            int second = ithchar(strings[i], 1) - 'a' + 1;
            //printf("Putting string %s at first %d and second %d\n", vals[i], first, second);
            bucket_append (&(buckets[first][second]), strings[i]);
        }
    } // for assigning elements into buckets

    // Sort the buckets
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++){
            recursive_merge_sort(buckets[i][j].elements, buckets[i][j].size);
        }
    } // for

    // Shove them back into the original array.
    int p = 0; // Index into original array
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++){
            char ** elements = buckets[i][j].elements;
            int size = buckets[i][j].size;
            for (int k = 0; k < size; k++) {
                strings[p++] = elements[k];
            } // for k
        } // for j
    } // for i

    // Clean up
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++){
            free(buckets[i][j].elements);
        }
    } // for
} // bucket_sort
