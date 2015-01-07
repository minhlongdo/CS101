#include "quicksort.h"

int quicksort_partition(int *array, int start, int end) {
  int pivot, i, j, t;
  pivot = array[start];
  i = start;
  j = end + 1;

  while(1) {
    do {
      ++i;
    } while(array[i] <= pivot && i <= end);
    do {
      --j;
    } while(array[j] > pivot);

    if (i >= j)
      break;

    t = array[i];
    array[i] = array[j];
    array[j] = t;
  }
  t = array[start];
  array[start] = array[j];
  array[j] = t;

  return j;
}

/* Implementation of quicksort */
void quicksort(int *array, int start, int end) {
  int pivot;
  if (start < end) {
    pivot = quicksort_partition(array, start, end);
    quicksort(array, pivot + 1, end);
    quicksort(array, start, pivot - 1);
  }
}
