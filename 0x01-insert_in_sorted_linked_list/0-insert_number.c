#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node at the correct spot in a sorted list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be inserted.
 * Return: Address of new element or NULL if it fails.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	if (new->n < current->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	while (current->next)
	{
		if (new->n >= current->n && new->n < current->next->n)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	current->next = new;
	return (new);
}
