#include "selectionsort.h"

int find_smallest(int *array, int i, int size) {
  int j;
  int min = i;
  for (j=i; j<size; j++) {
    if (array[min] > array[j])
      min = j;
  }
  return min;
}

/* Selection sort implementation */
void selection_sort(int *array, int size) {
  int i;
  for (i=0; i<size; i++) {
    int j;
    /* Find smallest in the index boundary of i and array size */
    int min = find_smallest(array, i, size);
    if (array[i] > array[min]) {
      int tmp = array[i];
      array[i] = array[min];
      array[min] = tmp;
    }
  }
}
