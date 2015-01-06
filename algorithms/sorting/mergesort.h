#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void merge(int *array, int l_start, int l_end, int r_start, int r_end);
void mergesort(int *array, int left, int right);
#endif
