#include "sort.h"

/**
* hoare_partition - Sort the sub-arrays
* @array: Sub-array of integers to be sorted
* @size: Size of the sub-array
* @lo: lower bound of sub-array
* @hi: upper bound of sub-array
*
* Return: The index where the array is splited
*/
int hoare_partition(int *array, size_t size, ssize_t lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j = hi + 1;
	int tmp;


	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j > i)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
* hoare_sort - Get the sub-arrays
* @array: Array of integers to be sorted
* @size: Size of the array
* @lo: lower bound of array
* @hi: upper bound of array
*/
void hoare_sort(int *array, size_t size, ssize_t lo, ssize_t hi)
{

	ssize_t pivot;

	if (lo < hi)
	{
		pivot = hoare_partition(array, size, lo, hi);
		hoare_sort(array, size, lo, pivot - 1);
		hoare_sort(array, size, pivot, hi);
	}
}

/**
* quick_sort_hoare - Sort an array of integers in ascending order
* using the Quick sort algorithm
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	if (array && size)
		hoare_sort(array, size, 0, size - 1);
}
