#include "insertionsort.h"
#include "selectionsort.h"

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
  
  return 0;
}
