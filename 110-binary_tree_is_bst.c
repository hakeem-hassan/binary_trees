#include <limits.h>  // For INT_MIN and INT_MAX

typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

int is_bst_helper(const binary_tree_t *tree, int min, int max);

int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    
    return is_bst_helper(tree, INT_MIN, INT_MAX);
}

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;
    
    // Ensure the current node's value is within the valid range
    if (tree->n <= min || tree->n >= max)
        return 0;

    // Recursively check the left and right subtrees with updated ranges
    return is_bst_helper(tree->left, min, tree->n) &&
           is_bst_helper(tree->right, tree->n, max);
}

