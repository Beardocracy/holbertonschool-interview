#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the n value to be inserted
 * Return: pointer to the newly created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = malloc(sizeof(heap_t));
	unsigned int numNodes;

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	if (*root == NULL)
	{
		*root = new;
		return (new);
	}
	numNodes = binaryTree_nodeCount(*root);
	insertAt_position(&new, *root, numNodes + 1);
	new = walkBack_theNode(new);
	if (new->parent == NULL)
		*root = new;
	return (new);
}

/**
 * binaryTree_nodeCount - returns the number of nodes in a binary tree
 * @root: pointer to the root of the tree
 * Return: int
 */
unsigned int binaryTree_nodeCount(heap_t *root)
{
	unsigned int count = 1;

	if (root->left != NULL)
	{
		count += binaryTree_nodeCount(root->left);
	}
	if (root->right != NULL)
	{
		count += binaryTree_nodeCount(root->right);
	}
	return (count);
}

/**
 * insertAt_position - inserts node at a specific position
 * @node: the node to insert
 * @parent: the root pointer
 * @position: the position in the binary tree to insert it
 * Return: pointer to the inserted node
 */
heap_t *insertAt_position(heap_t **node, heap_t *parent, int position)
{
	int arrSize = 0;
	int *turns;
	int i;
	int tempPos = position;

	/* Calculates the number of turns the directions will contain */
	while (tempPos > 1)
	{
		tempPos /= 2;
		arrSize++;
	}
	/* Creates an array the size of the number of turns to make. */
	turns = malloc(sizeof(int) * arrSize);
	if (turns == NULL)
		return (NULL);
	/* Populates the array with directions. 1 is left, 0 is right. */
	for (i = 0; position > 1; i++)
	{
		turns[i] = position % 2;
		position = position / 2;
	}
	for (i = arrSize - 1; i > 0; i--)
	{
		if (turns[i] == 0)
			parent = parent->left;
		else
			parent = parent->right;
	}
	if (turns[0] == 0)
	{
		parent->left = *node;
		(*node)->parent = parent;
	}
	else
	{
		parent->right = *node;
		(*node)->parent = parent;
	}
	free(turns);
	return (*node);
}

/**
 * walkBack_theNode - switches a node with it's parent continuously
 * until the parent is bigger or null
 * @node: the node to move into position
 * Return: pointer to the node
 */
heap_t *walkBack_theNode(heap_t *node)
{
	heap_t *temp, *tempP;

	while (node->parent != NULL && node->parent->n < node->n)
	{
		tempP = node->parent;
		temp = copy_heap_t(node);
		node->parent->parent = node;
		node->parent->left = node->left;
		node->parent->right = node->right;
		if (node->left != NULL)
			node->left->parent = node->parent;
		if (node->right != NULL)
			node->right->parent = node->parent;
		if (temp->right == node)
		{
			node->right = tempP;
			node->left = temp->left;
			if (temp->left != NULL)
				temp->left->parent = node;
		}
		else
		{
			node->left = tempP;
			node->right = temp->right;
			if (temp->right != NULL)
				temp->right->parent = node;
		}
		node->parent = temp->parent;
		if (node->parent != NULL)
		{
			if (node->parent->left == tempP)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		free(temp);
	}
	return (node);
}

/**
 * copy_heap_t - copies the contents of a heap_t to a mallocd heap_t
 * @node: the node to be copied
 * Return: pointer to the created node
 */
heap_t *copy_heap_t(heap_t *node)
{
	heap_t *copy;

	copy = malloc(sizeof(heap_t));
	if (copy == NULL)
		return (NULL);
	copy->parent = node->parent->parent;
	copy->left = node->parent->left;
	copy->right = node->parent->right;
	return (copy);
}
