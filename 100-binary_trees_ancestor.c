#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: the first node to compare with
 * @second: the second node to compare to
 *
 * Return: pointer to their common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t first_depth = 0, second_depth = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (second_depth > first_depth)
	{
		second  = second->parent;
		second_depth--;
	}

	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *) first);
}


/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the tree to be measured
 *
 * Return: node's depth, otherwise 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		++depth;
		tree = tree->parent;
	}

	return (depth);
}
