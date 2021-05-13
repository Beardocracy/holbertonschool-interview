#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * heap_size - finds number of nodes in a heap
 * @root: pointer to the root node of heap
 * Return: Number of nodes in the heap
 */
unsigned int heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (heap_size(root->right) + heap_size(root->left) + 1);
}

/**
 * down_sift - Sifts a root down to heapify a tree
 * @root: pointer to the root node of the tree
 */
void down_sift(heap_t *root)
{
	heap_t *swap, *left_node, *right_node;
	int temp;

	while (root)
	{
		swap = root;
		left_node = root->left;
		right_node = root->right;

		if (right_node && swap->n <= right_node->n)
			swap = right_node;
		if (left_node && swap->n <= left_node->n)
			swap = left_node;
		if (swap == root)
			return;
		temp = root->n;
		root->n = swap->n;
		swap->n = temp;
		root = swap;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value in root node
 */
int heap_extract(heap_t **root)
{
	unsigned int size, bit;
	int value;
	heap_t *temp;


	if (!root || !*root)
		return (0);
	size = heap_size(*root);
	value = (*root)->n;
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	temp = *root;
	bit = size;
	while (bit & (bit - 1))
		bit &= bit - 1;
	bit >>= 1;
	while (bit)
	{
		if (bit & size)
			temp = temp->right;
		else
			temp = temp->left;
		bit >>= 1;
	}
	(*root)->n = temp->n;
	if (temp->parent->right)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;
	free(temp);
	down_sift(*root);

	return (value);
}
