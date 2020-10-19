#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * number_of_sorts - Swap two nodes in a double linked list.
 * @array: node to swap with.
 * @size: the double linked list.
 * Return: counter
 */

unsigned int number_of_sorts(int *array, size_t size)
{
	unsigned int max = 0, n = 0;
	unsigned int count = 0;

	for (n = 0; n < size; n++)
	{
		if (max < (unsigned int)array[n])
			max = array[n];
	}
	while (max / 10 > 1)
	{
		max %= 10;
		count++;
	}
	return (count);
}
/**
 * source_of_sorts - Swap two nodes in a double linked list.
 * @out: node to swap with.
 * @size: the double linked list.
 * @in: node to swap with.
 * @k: the double linked list.
 */

void source_of_sorts(unsigned int *out, size_t size, unsigned int *in,
		     unsigned int k)
{
	unsigned int n = 0, i = 0;

	for (i = 0; i <= k; i++)
	{
		for (n = 0; n < size; n++)
		{
			out[n] = in[n] % 10;
			in[n] = in[n] / 10;
		}
	}
}
/**
 * radix_sort - Swap two nodes in a double linked list.
 * @array: node to swap with.
 * @size: the double linked list.
 */

void radix_sort(int *array, size_t size)
{
	unsigned int n = 0, *sort_aux, *src_srt, *src_srt_2;
	unsigned int i = 0, j = 0, n_sort = 0, k = 0;

	sort_aux = malloc(sizeof(unsigned int) * size);
	src_srt = malloc(sizeof(unsigned int) * size);
	src_srt_2 = malloc(sizeof(unsigned int) * size);
	for (n = 0; n < size; n++)
	{
		sort_aux[n] = 0;
		src_srt_2[n] = array[n];
	}
	n_sort = number_of_sorts(array, size);
	for (k = 0; k <= n_sort; k++)
	{
		source_of_sorts(src_srt, size, src_srt_2, k);
		j = 0;
		for (n = 0; n < size; n++)
		{
			for (i = 0; i < size; i++)
			{
				if (n == src_srt[i])
				{
					sort_aux[j] = array[i];
					j++;
				}
			}
		}
		for (n = 0; n < size; n++)
		{
			array[n] = sort_aux[n];
			src_srt_2[n] = array[n];
		}
		print_array(array, size);
	}
	free(sort_aux);
	free(src_srt);
	free(src_srt_2);
}
