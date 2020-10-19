#include "sort.h"

/**
* shell_sort -  Sort an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence.
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void shell_sort(int *array, size_t size)
{
	int current;
	size_t i, j, gap = 1;

	if (!array || size < 2)
		return;

	/*
	* get gap size, last highest number calculated
	* before going over the length of the array being sorted.
	*/
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			current = array[i];
			j = i;
			while (j >= gap - 1 && array[j - gap] > current)
			{
				array[j] = array[j - gap];
				j -=  gap;
			}
			array[j] = current;
		}
		print_array(array, size);
		/* next gap */
		gap = (gap - 1) / 3;
	}
}
