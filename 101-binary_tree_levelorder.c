#include "binary_trees.h"
#define Q_SIZE 500

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: pointer to the root node of tree to be traversed
 * @func: pointer to the function to be executed on each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front, rear;
	const binary_tree_t *temp = NULL;
	binary_tree_t **queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	temp = tree;
	queue = create_queue(&front, &rear);

	while (temp != NULL)
	{
		func(temp->n);

		if (tree->left)
			enqueue(queue, &rear, temp->left);

		if (tree->right)
			enqueue(queue, &rear, temp->right);

		temp = dequeue(queue, &front);
	}

	free(queue);
}

/**
 * create_queue - creates a queue
 * @front: (int) pointer to the first index
 * @rear: pointer to the rear index
 *
 * Return: pointer to the queue
 */

binary_tree_t **create_queue(int *front, int *rear)
{
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * Q_SIZE);
	*front = *rear = 0;

	return (queue);
}

/**
 * enqueue - adds an element to a queue
 * @queue: queue element to be inserted in
 * @rear: integer pointer to the rear
 * @node: element to be inserted in queue
 *
 * Return: void
 */

void enqueue(binary_tree_t **queue, int *rear, binary_tree_t *node)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - removes an element from a queue
 * @queue: queue to be acted on
 * @front: pointer to the front index
 *
 * Return: removed element
 */

binary_tree_t *dequeue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}
