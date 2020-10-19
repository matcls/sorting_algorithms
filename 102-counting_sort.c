#include "sort.h"
/**
 * counting_sort - its a simple sorting count
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int *srct_ar = NULL;
	unsigned int *ctn = NULL;
	unsigned int n = 0, max = 0;

	if (!array || size < 2)
		return;
	max = array[0];
	srct_ar = malloc(sizeof(unsigned int) * size);
	if (srct_ar == NULL)
		return;
	for (n = 0; n < size; n++)
	{
		if (max < (unsigned int)array[n])
			max = array[n];
	}
	ctn = malloc(sizeof(unsigned int) * (max + 1));
	if (ctn == NULL)
	{
		free(srct_ar);
		return;
	}
	for (n = 0; n <= max; n++)
		ctn[n] = 0;
	for (n = 0; n < size; n++)
		ctn[array[n]] += 1;
	for (n = 1; n <= max; n++)
		ctn[n] += ctn[n - 1];
	print_array((const int *)ctn, max + 1);
	for (n = 0; n < size; n++)
	{
		srct_ar[ctn[array[n]] - 1] = array[n];
		ctn[array[n]] -= 1;
	}
	for (n = 0; n < size; n++)
		array[n] = srct_ar[n];
	free(ctn);
	free(srct_ar);
}
