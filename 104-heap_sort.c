#include "sort.h"

/**
 * swap- swap two elements in an array.
 * @a: first element to swap.
 * @b: second element to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array representing a binary tree.
 * @size: The size of the array.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

/**
* heap_sort - Sort an array using the heap sort algorithm.
* @array: Array to be sorted.
* @size: size of the array.
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2 || !array)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
