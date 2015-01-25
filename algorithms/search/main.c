#include "binsearch.h"

void show_result(int result) {
  if (result == -1)
    printf("Key does not exist.\n");
  else
    printf("Key exists.\n");

  printf("\n");
}

int main() {
  int array[] = {1,2,3,4,5};
  int size = 5;
  printf ("Binary search\n");
  int index = binsearch(array, size, 2);
  show_result(index);
}
