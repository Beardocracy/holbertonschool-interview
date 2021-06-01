#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 * @head: Pointer to the first node in the list
 * Return: address of node of NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tort, *hare;

	if (!head)
	{
		return (NULL);
	}
	tort = head;
	hare = head;

	while (hare)
	{
		if (hare->next && hare->next->next)
			hare = hare->next->next;
		else
			return (NULL);
		tort = tort->next;

		if (tort == hare)
			break;
	}
	hare = head;
	while (tort != hare)
	{
		tort = tort->next;
		hare = hare->next;
	}
	return (tort);
}
