#include "search_algos.h"


/**
 * advanced_binary - searches for value in a sorted arr of integers
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	return (ab_recurse(array, 0, size - 1, value));
}

/**
 * array_printer - prints an array of integers
 * @array: index to first element of array
 * @start: first index to print
 * @end: last index
 */
void array_printer(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (i < end)
	{
		printf("%i, ", array[i]);
		i++;
	}
	printf("%i\n", array[i]);
}


/**
 * ab_recurse - recursively searches for value in array
 * @array: pointer to the first element in array
 * @index: left element in binary search
 * @stop: right element in binary search
 * @value: the value to find
 * Return: index of first match
 */
int ab_recurse(int *array, int index, int stop, int value)
{
	int mid = (stop + index) / 2;

	if (index > stop)
		return (-1);

	array_printer(array, index, stop);

	if (array[mid] < value)
		return (ab_recurse(array, mid + 1, stop, value));
	if (array[mid] > value)
		return (ab_recurse(array, index, mid, value));
	if (array[mid - 1] == value)
		return (ab_recurse(array, index, mid, value));

	return (mid);
}
