#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node to be performed on
 *
 * Return: pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	if (new_root->parent != NULL)
	{
		if (new_root->parent->right == tree)
			new_root->parent->right = new_root;

		else if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
	}
	tree->right = new_root->left;

	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->left = tree;

	return (new_root);
}
