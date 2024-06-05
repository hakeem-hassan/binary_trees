#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node structure
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function to perform a left rotation on a binary tree
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        // Can't perform left rotation if the tree is empty or has no right child
        return tree;
    }

    binary_tree_t *new_root = tree->right;

    // The right child's left subtree becomes the right subtree of the old root
    tree->right = new_root->left;
    if (new_root->left != NULL)
    {
        new_root->left->parent = tree;
    }

    // The old root becomes the left child of the new root
    new_root->left = tree;
    new_root->parent = tree->parent;

    // Update the parent of the old root
    tree->parent = new_root;

    // If the new root has a parent, update its child pointer
    if (new_root->parent != NULL)
    {
        if (new_root->parent->left == tree)
        {
            new_root->parent->left = new_root;
        }
        else if (new_root->parent->right == tree)
        {
            new_root->parent->right = new_root;
        }
    }

    return new_root;
}

