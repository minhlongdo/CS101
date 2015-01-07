#include "insertionsort.h"
#include "selectionsort.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"

/* Display array */
void display_array(int *array, int size) {
  int i;
  for (i=0; i<size; i++)
    printf("%i ", array[i]);
  printf("\n");
}

int main() {
  int i[] = {5,2,4,6,1,3};
  int size = 6;

  printf ("Insertion sort\n");
  display_array(i, size);
  insertion_sort(i, size);
  display_array(i, size);

  printf("\n");

  int a[] = {5,2,4,6,1,3};
  printf("Selection sort\n");
  display_array(a, size);
  selection_sort(a, size);
  display_array(a, size);

  printf ("\n");

  int b[] = {5,2,4,6,1,3};
  printf("Bubble sort\n");
  display_array(b, size);
  bubble_sort(b, size);
  display_array(b, size);

  printf("\n");

  int c[] = {5,2,4,6,1,3};
  printf("Merge sort\n");
  display_array(c, size);
  partition(c, 0, size-1);
  display_array(c, size);

  printf("\n");
  int d[] = {5,2,4,6,1,3};
  printf("Quick sort\n");
  display_array(d, size);
  quicksort(c, size);
  display_array(c, size);

  return 0;
}
