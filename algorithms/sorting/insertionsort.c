#include "insertionsort.h"

/* Insertion sort implementation */
void insertion_sort(int *array, int size) {
  int i;
  for (i=1; i<size; i++) {
    if (array[i] < array[i-1]) {
      /* Push the current one until it is in the correct position */
      int j = i;
      while(j > 0 && array[j] < array[j-1]) {
        int tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
        j--;
      }
    }
  }
}
