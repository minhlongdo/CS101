#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>

int quicksort_partition(int *array, int start, int end);
void quicksort(int *array, int start, int end);
void optimized_quicksort(int *array, int size);

#endif
