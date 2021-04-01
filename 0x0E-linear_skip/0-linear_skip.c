#include "search.h"

/**
 * linear_skip -  finds a value in sorted skip list
 * @list: pointer to head of list
 * @value: the target value
 * Return: Node with value or none
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tort, *hare;

	if (!list)
		return (NULL);

	hare = list;
	while (hare)
	{
		tort = hare;
		if (hare->express)
			hare = hare->express;
		else
		{
			while (hare->next)
				hare = hare->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n",
			hare->index, hare->n);
		if (value <= hare->n)
		{
			return (linear_help(hare, tort, value));
		}
	}
	return (linear_help(hare, tort, value));
}

/**
 * linear_help - helper function
 * @hare: pointer to lead node
 * @tort: pointer to follow node
 * @value: value to be searched
 * Return: Node with value or NULL
 */
skiplist_t *linear_help(skiplist_t *hare, skiplist_t *tort, int value)
{
	printf("Value found between indexes [%li] and [%li]\n",
		tort->index, hare->index);
	while (tort != hare->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
			tort->index, tort->n);
		if (tort->n == value)
			return (tort);
		tort = tort->next;
	}
	return (NULL);
}
