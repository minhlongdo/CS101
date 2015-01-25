#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort_partition(int *array, int size);
void quicksort(int *array, int size);
void optimized_quicksort(int *array, int size);

#endif
