#include <stdio.h>
#include <stdlib.h>

// Definition of the AVL tree node
typedef struct avl_s {
    int value;
    struct avl_s *left;
    struct avl_s *right;
    int height;
} avl_t;

// Function to create a new AVL tree node
avl_t *new_node(int value) {
    avl_t *node = (avl_t *)malloc(sizeof(avl_t));
    if (!node) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// A utility function to get the height of the tree
int height(avl_t *node) {
    if (!node) return 0;
    return node->height;
}

// A utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotate subtree rooted with y
avl_t *right_rotate(avl_t *y) {
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
avl_t *left_rotate(avl_t *x) {
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node
int get_balance(avl_t *node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

// Recursive function to insert a value in the subtree rooted with node and returns the new root of the subtree
avl_t *insert(avl_t *node, int value) {
    if (!node) return new_node(value);

    // Duplicate values are not allowed in BST
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Equal values are ignored
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = get_balance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to build an AVL tree from an array
avl_t *array_to_avl(int *array, size_t size) {
    if (!array || size == 0) return NULL;

    avl_t *root = NULL;

    for (size_t i = 0; i < size; i++) {
        root = insert(root, array[i]);
    }

    return root;
}

// Function to print the in-order traversal of the tree
void inorder(avl_t *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Main function for testing the array_to_avl function
int main() {
    int array[] = {10, 20, 30, 40, 50, 25};
    size_t size = sizeof(array) / sizeof(array[0]);

    avl_t *root = array_to_avl(array, size);

    printf("In-order traversal of the constructed AVL tree is \n");
    inorder(root);

    return 0;
}

