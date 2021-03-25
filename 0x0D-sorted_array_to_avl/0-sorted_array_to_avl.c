#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Sorted array to AVL tree
 *
 * @array: The array of ints
 * @size: length of the array
 *
 * Return: Pointer to the root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (!array || !size)
		return (NULL);

	head = recurse_sorted_arr_to_avl(array, 0, size - 1, NULL);

	return (head);
}

/**
 * recurse_sorted_arr_to_avl - recursively fills out AVL tree
 *
 * @array: array of ints
 * @start: left index
 * @end: right index
 * @parent: the node->parent value
 *
 * Return: pointer to root node
 */
avl_t *recurse_sorted_arr_to_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = new_node(array[mid], parent);

	root->left = recurse_sorted_arr_to_avl(array, start, mid - 1, root);
	root->right = recurse_sorted_arr_to_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * new_node - creates a new avl_t node
 *
 * @data: the n value for the node
 * @parent: the parent value
 *
 * Return: pointer to the new node
 */
avl_t *new_node(int data, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->n = data;

	return (node);
}
