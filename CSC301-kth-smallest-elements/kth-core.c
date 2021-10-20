#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "strutils.h"
#include "kth-core.h"

void print_array(char *arr[], int len){
    printf("[");
    for (int i = 0; i < len - 1; i++){
        printf("%s, ", arr[i]);
    }
    printf("%s]\n", arr[len - 1]);
}

char* kth(int k, char *arr[], int len){
    bool testing = false;
    // Randomly assign a pivot
    srand(time(NULL));
    int pivot = rand() % len;
    char* pivotStr = arr[pivot];
    // swap pivot to be the first one
    swap(0, pivot, arr);
    // Initialize pointers: s : smaller, e : equal
    // i : not seen yet, l : larger
    int s = 1, e = 1, i = 1, l = len;
    if (testing){
        printf("==========================================\n");
        printf("Pivot is %s, and k is %d, and len is %d.\n", arr[0], k, len);
        printf("Before pivoting: ");
        print_array(arr, len);
    }
    while (i < l){ // while we have not seen all the elements
        if (strcmp(arr[i], arr[0]) < 0){ // smaller case
            // swap with equal element and increment both e and i
            swap(e++, i++, arr);
        }
        else if (strcmp(arr[i], arr[0]) == 0){ // equal case
            // simply increment i
            i++;
        }
        else{ // larger case
            // swap with the last element and decrement l
            swap(i, --l, arr);
        }
    }
    // swap the pivot into the correct position.
    swap(--s, --e, arr);
    int smallNum = e, equalNum = l - e, largeNum = len - l;
    if (testing){
        printf("smallNum : %d, equalNum : %d, largeNum : %d\n", smallNum, equalNum, largeNum);
        printf("s : %d, e : %d, i : %d, l = %d\n", s, e, i, l);
        printf("After pivoting: ");
        print_array(arr, len);
    }
    if (k < smallNum){
        return kth(k, arr, smallNum);
    }
    else if (k >= smallNum && k < smallNum + equalNum){
        // printf("OutputEqual: %s\n", arr[e]);
        return arr[e];
    }
    else{ // k >= smallNum + equalNum
        return kth(k - smallNum - equalNum, arr + smallNum + equalNum, largeNum);
    }
}
