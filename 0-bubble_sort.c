#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
* using the Bubble sort algorithm.
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	int count = 1;
	int swap = 0;

	if (size < 2)
		return;

	while (count > 0)
	{
		count = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i + 1];
				array[i + 1] = array[i];
				array[i] = swap;
				count += 1;
				print_array(array, size);
			}
		}
	}
}
