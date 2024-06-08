#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node to be performed on
 *
 * Return: pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;

	/* Update parent pointers */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* Update the parent's child pointer if tree was not the root */
	if (new_root->parent != NULL)
	{
		if (new_root->parent->right == tree)
			new_root->parent->right = new_root;

		else if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
	}

	/* Perform the rotation */
	tree->left = new_root->right;

	if (new_root->right != NULL)
		new_root->right->parent = tree;

	new_root->right = tree;

	return (new_root);
}
