#include "insertionsort.h"

/* Insertion sort implementation */
void insertion_sort(int *array, int size) {
  int i;
  for (i=1; i<size; i++) {
    if (array[i] < array[i-1]) {
      /* Push the current one until it is in the correct position */
      int j;
      for (j = i; j > 0; j--) {
        if (array[j] < array[j-1]) {
          /* Swap values */
          int tmp = array[j];
          array[j] = array[j-1];
          array[j-1] = tmp;
        } else {
          break;
        }
      }
    }
  }
}

/* Display array */
void display_array(int *array, int size) {
  int i;
  for (i=0; i<size; i++)
    printf("%i ", array[i]);
  printf("\n");
}
