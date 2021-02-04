#include "lists.h"
#include <stdlib.h>

/**
 * check_cycle - checks a linked list for a cycle
 * @list: the head of the list to check
 * Return: 0 if no cycle, 1 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *tort = list;
	listint_t *hare = list;

	while (hare != NULL)
	{
		tort = tort->next;
		hare = hare->next;
		if (hare != NULL)
			hare = hare->next;
		if (tort == hare && hare)
			return (1);
	}
	return (0);
}
