#include "sort.h"

/**
* partition - Sort the sub-arrays
* @array: Sub-array of integers to be sorted
* @size: Size of the sub-array
* @lo: lower bound of sub-array
* @hi: upper bound of sub-array
*
* Return: The index where the array is splited
*/
size_t partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	ssize_t index = lo;

	while (index < hi)  /* last element is the  pivot */
	{
		if (array[index] < array[hi])
		{
			if (lo != index)
			{
				/*Swap the  integers and sort the first partition */
				array[lo] ^= array[index];
				array[index] ^= array[lo];
				array[lo] ^= array[index];
				print_array(array, size);
			}
			lo += 1;
		}
		index += 1;
	}
	if (array[lo] != array[hi])
	{
		/* Sort the other partition */
		array[lo] ^= array[hi];
		array[hi] ^= array[lo];
		array[lo] ^= array[hi];
		print_array(array, size);
	}
	return (lo);
}

/**
* sort - Get the sub-arrays
* @array: Array of integers to be sorted
* @size: Size of the array
* @lo: lower bound of array
* @hi: upper bound of array
*/

void sort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	ssize_t p;

	if (lo < hi)
	{
		/* keeps partitioning and sorting until the array is all sorted */
		p = partition(array, size, lo, hi);
		sort(array, size, lo, p - 1);
		sort(array, size, p + 1, hi);
	}
}

/**
* quick_sort - Sort an array of integers in ascending order
* using the Quick sort algorithm
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	if (array && size)
		sort(array, size, 0, size - 1);

}
