#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
    {
        return NULL;
    }

    binary_tree_t *parent = node->parent;
    binary_tree_t *grandparent = parent->parent;

    if (grandparent->left == parent)
    {
        return grandparent->right;
    }
    else
    {
        return grandparent->left;
    }
}

// Helper function to create a new node
binary_tree_t *new_node(int value)
{
    binary_tree_t *node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (node == NULL)
    {
        return NULL;
    }
    node->n = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to link parent and child nodes
void link_nodes(binary_tree_t *parent, binary_tree_t *left, binary_tree_t *right)
{
    if (parent != NULL)
    {
        parent->left = left;
        parent->right = right;
        if (left != NULL)
        {
            left->parent = parent;
        }
        if (right != NULL)
        {
            right->parent = parent;
        }
    }
}

// Helper function to print a node value
void print_node(binary_tree_t *node)
{
    if (node != NULL)
    {
        printf("%d\n", node->n);
    }
    else
    {
        printf("NULL\n");
    }
}

int main()
{
    // Create nodes
    binary_tree_t *root = new_node(1);
    binary_tree_t *node2 = new_node(2);
    binary_tree_t *node3 = new_node(3);
    binary_tree_t *node4 = new_node(4);
    binary_tree_t *node5 = new_node(5);
    binary_tree_t *node6 = new_node(6);
    binary_tree_t *node7 = new_node(7);

    // Link nodes
    link_nodes(root, node2, node3);
    link_nodes(node2, node4, node5);
    link_nodes(node3, node6, node7);

    // Find uncle
    binary_tree_t *uncle = binary_tree_uncle(node5);
    print_node(uncle); // Should print 3, the value of node3

    // Cleanup
    free(root);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);

    return 0;
}

