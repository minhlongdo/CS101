#include "mergesort.h"

void merge(int *array, int l_start, int l_end, int r_start, int r_end) {
	int l_len = l_end - l_start;
	int r_len = r_end - r_start;

	int l_half[l_len];
	int r_half[r_len];

	int i = l_start, l=0, r=0;

	printf("Size of left: %i\n", l_len);
	printf("Size of right: %i\n", r_len);

	/* Copy values into temporary list */
	for(i=l_start; i<l_len; i++, l++)
		l_half[l] = array[i];

	for (i=r_start; i<r_len; i++, r++)
		r_half[r] = array[i];

	/* Merge the values back into positions in the main list */
	for (i=l_start, r=0, l=0; l < l_len && r < r_len; i++) {
		if (l_half[l] < r_half[r]) {
			array[i] = l_half[l];
			l++;
		}
		else {
			array[i] = r_half[r];
			r++;
		}
	}

	/* Handle the leftover values */
	for ( ; l < l_len; i++, l++)
		array[i] = l_half[l];

	for ( ; r < r_len; i++, r++)
		array[i] = r_half[r];

	printf("\n");
}

void mergesort(int *array, int left, int right) {
	/* Base case */
	if (right - left <= 1)
		return;

		int l_start = left;
		int l_end = (left+right)/2;
		int r_start = l_end;
		/* Size of the array */
		int r_end = right;

		printf("Left start: %i\n", l_start);
		printf("Left end: %i\n", l_end);
		printf("Right start: %i\n", r_start);
		printf("Right end: %i\n", r_end);

		mergesort(array, l_start, l_end);
		mergesort(array, r_start, r_end);
		/* Merge the sorted left and right halves back together */
		merge(array, l_start, l_end, r_start, r_end);

		int i;
		for (i=0; i < r_end; i++)
			printf("%i ", array[i]);
		printf("\n");
}
