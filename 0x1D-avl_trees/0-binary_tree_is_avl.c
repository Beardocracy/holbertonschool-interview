#include <stdio.h>
#include "binary_trees.h"


/**
 * tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
int tree_height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	if (tree == NULL)
		return (0);

	height_l = tree_height(tree->left);
	height_r = tree_height(tree->right);
	return ((height_l > height_r ? height_l : height_r) + 1);
}

/**
 * tree_balance - checks if a tree is balanced by height
 * @tree: pointer to the node
 * Return: 1 if balanced, 0 if not.
 */
int tree_balance(const binary_tree_t *tree)
{
	int height_dif = 0;

	if (tree == NULL)
		return (1);

	height_dif = tree_height(tree->left) - tree_height(tree->right);
	if (height_dif > 1 || height_dif < -1)
		return (0);

	return (1);
}

/**
 * balance_recurse - recursively checks a tree for balanced height
 * @tree: Pointer to root node
 * Return: 1 if balanced, 0 otherwise
 */
int balance_recurse(const binary_tree_t *tree)
{
	int balanced;

	if (tree == NULL)
		return (1);

	balanced = tree_balance(tree);

	if (balanced && balance_recurse(tree->left) &&
		balance_recurse(tree->right))
	{
		return (1);
	}

	return (0);
}

/**
 * is_bst - Checks if a tree is a BST
 * @tree: Pointer to root node
 * @min: Pointer to current min
 * @max: Pointer to current max
 * Return: 1 if BST, or 0
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
	const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (min && min->n >= tree->n)
		return (0);
	if (max && max->n <= tree->n)
		return (0);
	return (is_bst(tree->left, min, tree) &
		is_bst(tree->right, tree, max));
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: pointer to the head of the tree
 * Return: 1 if valid, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (balance_recurse(tree) && is_bst(tree, NULL, NULL));
}
