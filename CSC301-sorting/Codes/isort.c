#include "sorter.h"
#include "bucket-sort.h"

int 
main(int argc, char *argv[])
{
  return sort_main (bucket_sort, argc, argv);
} // main
