#include <stdio.h>
#include <stdlib.h>

// Define the structure of the binary tree node
typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Helper function to calculate the depth of the leftmost leaf
int leftmost_depth(const binary_tree_t *tree) {
    int depth = 0;
    while (tree != NULL) {
        depth++;
        tree = tree->left;
    }
    return depth;
}

// Helper function to check if the tree is perfect
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level) {
    if (tree == NULL) {
        return 1;
    }

    // If it's a leaf node, check if it's at the correct depth
    if (tree->left == NULL && tree->right == NULL) {
        return depth == level + 1;
    }

    // If it's an internal node and doesn't have two children, it's not perfect
    if (tree->left == NULL || tree->right == NULL) {
        return 0;
    }

    // Recursively check the left and right subtrees
    return is_perfect_recursive(tree->left, depth, level + 1) &&
           is_perfect_recursive(tree->right, depth, level + 1);
}

// Function to check if a binary tree is perfect
int binary_tree_is_perfect(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }

    int depth = leftmost_depth(tree);
    return is_perfect_recursive(tree, depth, 0);
}

