#include <stddef.h>

// Define the structure for a binary tree node
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function to count the leaves in a binary tree
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    // If the tree is NULL, there are no leaves
    if (tree == NULL)
        return 0;

    // If the current node is a leaf (both children are NULL)
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    // Otherwise, recursively count the leaves in the left and right subtrees
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}


