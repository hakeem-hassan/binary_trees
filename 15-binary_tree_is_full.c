#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of tree to be checked
 *
 * Return: 1 if full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If both left and right children are present, check recursively */
	if (tree->right != NULL && tree->left != NULL)
		return (binary_tree_is_full(tree->right) && binary_tree_is_full(tree->left));

	/* If both left and right children are absent, it's a leaf node*/
	if (tree->right == NULL && tree->left == NULL)
		return (1);

	return (0);
}
