#include "binary_trees.h"

/**
 * binary_tree_balance - measures a binary tree's balance factor
 * @tree: pointer to the root node of tree to be measured
 *
 * Return: the balance factor of the tree, otherwise 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: (size_t) height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height = 0, left_height = 0;

	if (tree == NULL)
		return (-1);

	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return ((right_height > left_height) ? right_height : left_height);
}
