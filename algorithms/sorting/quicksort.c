#include "quicksort.h"

void quicksort_partition(int *array, int size) {
  /* If partition of size 0 or 1 are already sorted. */
  if (size <= 1)
    return;

  /* Select a pivot from the array randomly */
  int pivot = array[rand() % size];

  int lower = 0;
  int upper = size - 1;

  while (lower < upper) {
    /* Partition array into sections above and below the pivot */
    while(array[lower] < array[pivot])
      ++lower;

    while(array[upper] > array[pivot])
      --upper;

    /* Swap entries at the lower and upper indices */
    int temp = array[lower];
    array[lower] = array[upper];
    array[upper] = temp;
  }
  /* Recursively call partition on each partition */
  quicksort_partition(array, lower);
  quicksort_partition(&(array[lower + 1]), size - lower - 1);
}

/* Implementation of quicksort */
void quicksort(int *array, int size) {
  /* Seed a random number generator */
  srand((unsigned int)time(0));
  quicksort_partition(array, size);
}
