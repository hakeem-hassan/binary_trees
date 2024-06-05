#include <stdlib.h>

// Define the structure for AVL tree nodes
typedef struct avl_s
{
    int n;
    struct avl_s *left;
    struct avl_s *right;
} avl_t;

// Helper function to recursively build the AVL tree
avl_t *build_avl_tree(int *array, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Find the middle element of the current subarray
    int mid = (start + end) / 2;

    // Allocate memory for the new node and set its value
    avl_t *node = malloc(sizeof(avl_t));
    if (node == NULL) {
        return NULL;
    }
    node->n = array[mid];
    node->left = NULL;
    node->right = NULL;

    // Recursively build the left and right subtrees
    node->left = build_avl_tree(array, start, mid - 1);
    node->right = build_avl_tree(array, mid + 1, end);

    return node;
}

// Main function to convert a sorted array to an AVL tree
avl_t *sorted_array_to_avl(int *array, size_t size) {
    if (array == NULL || size == 0) {
        return NULL;
    }
    return build_avl_tree(array, 0, size - 1);
}

