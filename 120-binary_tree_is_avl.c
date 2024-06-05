#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Helper function to get the height of a tree
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

// Helper function to check if a tree is a binary search tree
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n <= min || tree->n >= max)
        return 0;

    return is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max);
}

// Main function to check if the tree is a valid AVL tree
int is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    if (abs(left_height - right_height) > 1)
        return 0;

    return is_bst(tree, INT_MIN, INT_MAX) && is_avl(tree->left) && is_avl(tree->right);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return is_avl(tree);
}

