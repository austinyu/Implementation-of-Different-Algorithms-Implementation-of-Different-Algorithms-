#include "kth-core.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    // Modify the commandline arguments to exclude the first one
    // find the 3rd smallest
    int k = argv[1][0] - '0';
    argv += 2;
    argc -= 2;
    char* res = kth(k, argv, argc);
    printf("%s\n", res);
    return 0;
}


