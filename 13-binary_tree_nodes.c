#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: root node of tree to be calculated
 *
 * Return: number of specified nodes, 0 otherwise
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
		return (0);

	return (1 + binary_tree_nodes(tree->right) + binary_tree_nodes(tree->left));
}
