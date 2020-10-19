#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0;
	int tmp = 0;
	unsigned int j = 0;
	unsigned int ctn = 0;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		ctn = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[ctn] > array[j])
				ctn = j;
		}
		if (ctn != i)
		{
			tmp = array[i];
			array[i] = array[ctn];
			array[ctn] = tmp;
			print_array(array, size);
		}
	}
}
