#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node the new one will point to
 * @value: the n value to insert
 * Return: pointer to the newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
