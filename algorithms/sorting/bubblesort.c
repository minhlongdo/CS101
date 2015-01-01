#include "bubblesort.h"

/* Implementation of Bubble sort*/
void bubble_sort(int *array, int size) {
  int sorted;
  int i;
  while (1) {
    /* Reset flag for every pass */
    sorted = 0;
    for (i=1; i<size; i++) {
      if(array[i] < array[i-1]) {
        int tmp = array[i];
        array[i] = array[i-1];
        array[i-1] = tmp;
        sorted = -1;
      }
    }
    if (sorted == 0)
      break;
  }
}
