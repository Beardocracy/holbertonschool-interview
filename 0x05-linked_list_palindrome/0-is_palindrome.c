#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *tort = *head;
	listint_t *hare = *head;
	listint_t *first_half = *head;
	listint_t *second_half = NULL;
	listint_t *second_half_temp;

	if ((*head) == NULL || (*head)->next == NULL)
		return (1);
	while (hare->next && hare->next->next)
	{
		hare = hare->next->next;
		tort = tort->next;
	}

	second_half = reverse_list(tort->next);
	second_half_temp = second_half;

	while (first_half && second_half)
	{
		if (first_half->n != second_half->n)
		{
			tort->next = reverse_list(second_half_temp);
			return (0);
		}
		second_half = second_half->next;
		first_half = first_half->next;
	}

	tort->next = reverse_list(second_half_temp);
	return (1);
}

/**
 * reverse_list - reverses a linked list.
 * @head: the head of the list to be reversed.
 * Return: the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *new = NULL;
	listint_t *next;

	while (head)
	{
		next = head->next;
		head->next = new;
		new = head;
		head = next;
	}
	return (new);
}
