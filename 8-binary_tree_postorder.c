#include <stddef.h>

// Define the structure for the binary tree node
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function to perform post-order traversal
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    // Check if the tree or func is NULL
    if (tree == NULL || func == NULL)
    {
        return;
    }

    // Recursively traverse the left subtree
    binary_tree_postorder(tree->left, func);

    // Recursively traverse the right subtree
    binary_tree_postorder(tree->right, func);

    // Apply the function to the current node's value
    func(tree->n);
}

