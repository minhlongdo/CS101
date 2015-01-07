#include "quicksort.h"

int quicksort_partition(int *array, int start, int end) {
  int pivot, i, j, t;
  /* First element is the pivot */
  pivot = array[start];
  i = start;
  j = end + 1;

  while(1) {
    /*
    Go through until array is either greater than the pivot
    or it gets to the end of the list. From left to right.
    */
    do {
      ++i;
    } while(array[i] <= pivot && i <= end);
    /*
    Go from right to left while the element is greater than the pivot.
    */
    do {
      --j;
    } while(array[j] > pivot);

    /*
    If the left 'wall' position is infront of the the right 'wall':
    Terminate the loop.
    */
    if (i >= j)
      break;

    /*
    Exchange values between the position of the ith and jth element.
    */
    t = array[i];
    array[i] = array[j];
    array[j] = t;
  }
  /**/
  t = array[start];
  array[start] = array[j];
  array[j] = t;
  /* Position of the pivot */
  return j;
}

/* Implementation of quicksort */
void quicksort(int *array, int start, int end) {
  int pivot;
  if (start < end) {
    pivot = quicksort_partition(array, start, end);
    /*
    Add 1 and subtract -1 because one know the pivot is in the correct position
    */
    quicksort(array, pivot + 1, end);
    quicksort(array, start, pivot - 1);
  }
}
