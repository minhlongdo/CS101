#include "binsearch.h"

/*
Binary search:
Assuming the list is sorted ascendingly.
*/
int binsearch(int *array, int size, int key) {
  int lower = 0;
  int upper = size - 1;
  int mid = (lower + upper)/2;

  while (lower <= upper) {
    if (array[mid] < key)
      lower = mid + 1;
    else if (array[mid] == key)
      return mid;
    else
      upper = mid - 1;
    mid = (lower + upper)/2;
  }
  return -1;
}
