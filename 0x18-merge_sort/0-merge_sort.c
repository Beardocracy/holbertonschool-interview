#include "sort.h"

/**
 * merge_sort - Sorts an array
 * @array: Pointer to first element of int array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (size <= 1 || !array)
		return;

	temp = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		temp[i] = array[i];
	td_merge(temp, array, 0, size);
	free(temp);
}

/**
 * merge_two - Merges two arrays
 * @array: reference array
 * @temp: array to modify
 * @start: Starting index
 * @end: Ending index
 * @middle: Where the sides are split
 */
void merge_two(int *array, int *temp, size_t start, size_t end, size_t middle)
{
	size_t i, j, k;

	i = start;
	j = middle;
	printf("Merging...\n[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);

	for (k = start; k < end; k++)
	{
		if ((j >= end || array[i] <= array[j]) && i < middle)
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(temp + start, end - start);
}

/**
 * td_merge - Merges recursively using top down method
 * @temp: Pointer to the start of array
 * @array: Pointer to the start of reference array
 * @start: The index to start split at
 * @end: Index to end split
 */
void td_merge(int *temp, int *array, size_t start, size_t end)
{
	size_t middle;

	if (end - start <= 1)
		return;
	middle = (start + end) / 2;
	td_merge(array, temp, start, middle);
	td_merge(array, temp, middle, end);
	merge_two(temp, array, start, end, middle);
}
