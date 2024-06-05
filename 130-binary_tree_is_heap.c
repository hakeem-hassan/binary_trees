#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function prototypes
int binary_tree_is_heap(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, int index, int number_nodes);
int count_nodes(const binary_tree_t *tree);
int is_max_heap(const binary_tree_t *tree);

int binary_tree_is_heap(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    
    int node_count = count_nodes(tree);
    int index = 0;

    if (is_complete(tree, index, node_count) && is_max_heap(tree)) {
        return 1;
    }
    
    return 0;
}

int count_nodes(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int is_complete(const binary_tree_t *tree, int index, int number_nodes) {
    if (tree == NULL) {
        return 1;
    }

    if (index >= number_nodes) {
        return 0;
    }

    return is_complete(tree->left, 2 * index + 1, number_nodes) &&
           is_complete(tree->right, 2 * index + 2, number_nodes);
}

int is_max_heap(const binary_tree_t *tree) {
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }

    if (tree->right == NULL) {
        return tree->n >= tree->left->n;
    }

    if (tree->n >= tree->left->n && tree->n >= tree->right->n) {
        return is_max_heap(tree->left) && is_max_heap(tree->right);
    }

    return 0;
}

