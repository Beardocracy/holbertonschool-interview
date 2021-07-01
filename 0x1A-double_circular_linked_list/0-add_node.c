#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Adds new node to end of circular linked list
 * @list: Pointer to the head of the ll
 * @str: the data for the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *head, *end;

	new = malloc(sizeof(List *));
	if (!new)
		return (NULL);
	new->str = str;
	head = *list;

	if (head == NULL)
	{
		*list = new;
		return (new);
	}

	if (head->prev == NULL)
	{
		head->next = new;
		head->prev = new;
		new->next = head;
		new->prev = head;
		return (new);
	}

	end = head->prev;
	end->next = new;
	new->next = head;
	new->prev = end;
	head->prev = new;
	return (new);
}

/**
 * add_node_begin - Adds new node to beginning of circular linked list
 * @list: Pointer to the head of the ll
 * @str: the data for the new node
 * Return: address of new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *head, *end;

	new = malloc(sizeof(List *));
	if (!new)
		return (NULL);
	new->str = str;
	head = *list;

	if (head == NULL)
	{
		*list = new;
		return (new);
	}

	if (head->prev == NULL)
	{
		head->next = new;
		head->prev = new;
		new->next = head;
		new->prev = head;
		*list = new;
		return (new);
	}

	end = head->prev;
	end->next = new;
	head->prev = new;
	new->prev = end;
	new->next = head;
	*list = new;
	return (new);
}
