#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function to calculate the height of a binary tree.
int tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}

// Function to calculate the balance factor of a binary tree node.
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    return left_height - right_height;
}

// Helper function to create a new binary tree node.
binary_tree_t *create_node(int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
