#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: pointer to the head of array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;

	if (size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}

/**
 * count_sort - does counting sort on an array according to the digit exp
 * @array: pointer to the array
 * @size: the size of the array
 * @exp: the digits place we are sorting by
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output;
	int count[10], digit, magic;
	int i;

	output = (int *)malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 0; i < (int)size; i++)
		output[i] = 0;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		magic = (array[i] / exp) % 10;
		output[count[magic] - 1] = array[i];
		count[magic]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(output);
	print_array(array, size);
}


