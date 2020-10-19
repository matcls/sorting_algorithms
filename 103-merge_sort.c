#include "sort.h"


void top_down_merge(size_t start, size_t middle, size_t end, int *dest,
	int *source)
{
	size_t i = start, j = middle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);

	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
			dest[k] = source[i], i++;
		else
			dest[k] = source[j], j++;
	}

	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* top_down_split_merge - Split the given array
* and merge the sorted sub-arrays.
* @array: Array of integers to be sorted.
* @copy: A copy of the array.
* @start: lower bound of array (inclusive).
* @end: upper bound of array (exclusive).
*/
void top_down_split_merge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	/* if run size == 1  consider it sorted */
	if (end - start < 2)
		return;

	middle = (start + end) / 2; /* split into halves */
	/* recursively sort both runs from array A[] into B[] */
	top_down_split_merge(start, middle, array, copy);
	top_down_split_merge(middle, end, array, copy);
	top_down_merge(start, middle, end, array, copy);

	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
* merge_sort - Sort an array of integers in ascending order
* using the Merge sort algorithm.
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy = NULL;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	/* Copy array */
	for (i = 0; i < size; i++)
		copy[i] = array[i];

	top_down_split_merge(0, size, array, copy);
	free(copy);
}
