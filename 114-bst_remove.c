#include <stdio.h>
#include <stdlib.h>

// Definition of the binary search tree node
typedef struct bst_t {
    int value;
    struct bst_t *left;
    struct bst_t *right;
} bst_t;

// Function to find the minimum value node in a tree
bst_t *minValueNode(bst_t *node) {
    bst_t *current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to remove a node from the BST
bst_t *bst_remove(bst_t *root, int value) {
    // Base case
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (value < root->value) {
        root->left = bst_remove(root->left, value);
    } else if (value > root->value) {
        root->right = bst_remove(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        bst_t *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = bst_remove(root->right, temp->value);
    }

    return root;
}

// Function to create a new BST node
bst_t *newNode(int value) {
    bst_t *temp = (bst_t *)malloc(sizeof(bst_t));
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given value in BST
bst_t *insert(bst_t *node, int value) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(value);
    }

    // Otherwise, recur down the tree
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to do inorder traversal of BST
void inorder(bst_t *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}
