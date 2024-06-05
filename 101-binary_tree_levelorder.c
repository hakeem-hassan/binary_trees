#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Queue node structure
typedef struct queue_node_s
{
    const binary_tree_t *tree_node;
    struct queue_node_s *next;
} queue_node_t;

// Queue structure
typedef struct queue_s
{
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

// Function to create a new queue
queue_t *create_queue()
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add a tree node to the queue
void enqueue(queue_t *queue, const binary_tree_t *tree_node)
{
    if (!queue || !tree_node)
        return;
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;
    new_node->tree_node = tree_node;
    new_node->next = NULL;
    if (!queue->rear)
    {
        queue->front = queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to remove a tree node from the queue
const binary_tree_t *dequeue(queue_t *queue)
{
    if (!queue || !queue->front)
        return NULL;
    queue_node_t *temp = queue->front;
    const binary_tree_t *tree_node = temp->tree_node;
    queue->front = queue->front->next;
    if (!queue->front)
    {
        queue->rear = NULL;
    }
    free(temp);
    return tree_node;
}

// Function to check if the queue is empty
int is_queue_empty(queue_t *queue)
{
    return (queue->front == NULL);
}

// Function to free the queue
void free_queue(queue_t *queue)
{
    while (!is_queue_empty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

// Level-order traversal function
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    queue_t *queue = create_queue();
    if (!queue)
        return;

    enqueue(queue, tree);

    while (!is_queue_empty(queue))
    {
        const binary_tree_t *current = dequeue(queue);
        func(current->n);
        if (current->left)
            enqueue(queue, current->left);
        if (current->right)
            enqueue(queue, current->right);
    }

    free_queue(queue);
}

// Example function to print the value of a node
void print_node_value(int value)
{
    printf("%d\n", value);
}

// Example usage
int main()
{
    // Create a simple binary tree
    binary_tree_t node1 = {1, NULL, NULL};
    binary_tree_t node2 = {2, NULL, NULL};
    binary_tree_t node3 = {3, NULL, NULL};
    binary_tree_t node4 = {4, NULL, NULL};
    binary_tree_t node5 = {5, NULL, NULL};
    binary_tree_t root = {0, &node1, &node2};

    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;

    // Perform level-order traversal
    binary_tree_levelorder(&root, print_node_value);

    return 0;
}

