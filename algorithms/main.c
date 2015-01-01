#include "insertionsort.h"



int main() {
  int i[] = {5,2,4,6,1,3};
  int size = 6;
  display_array(i, size);
  insertion_sort(i, size);
  display_array(i, size);
  return 0;
}
