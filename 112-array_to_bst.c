#include <stdlib.h>
#include <stddef.h>

// Definition of a BST node
typedef struct bst_s {
    int value;
    struct bst_s *left;
    struct bst_s *right;
} bst_t;

// Function to create a new BST node
bst_t *create_node(int value) {
    bst_t *new_node = (bst_t *)malloc(sizeof(bst_t));
    if (!new_node) {
        return NULL;
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a value into the BST
bst_t *insert_node(bst_t *root, int value) {
    if (!root) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else if (value > root->value) {
        root->right = insert_node(root->right, value);
    }
    // If value is already present, it is ignored
    return root;
}

// Function to convert an array to a BST
bst_t *array_to_bst(int *array, size_t size) {
    if (!array || size == 0) {
        return NULL;
    }

    bst_t *root = NULL;
    for (size_t i = 0; i < size; i++) {
        root = insert_node(root, array[i]);
    }

    return root;
}

