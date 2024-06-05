#include <stddef.h>

// Definition for the binary tree node structure.
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    struct binary_tree_s *parent;
} binary_tree_t;

size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL)
        return 0;

    // Traverse up the tree, counting the nodes until the root is reached
    while (tree->parent != NULL)
    {
        depth++;
        tree = tree->parent;
    }

    return depth;
}

