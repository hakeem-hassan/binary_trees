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
	int front = 0, rear = 0;
	const binary_tree_t *temp = NULL;
	binary_tree_t **queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue(&front, &rear);

	enqueue(queue, &rear, tree);

	while (front < rear)
	{
		temp = dequeue(queue, &front);

		func(temp->n);

		if (temp->left)
			enqueue(queue, &rear, temp->left);

		if (temp->right)
			enqueue(queue, &rear, temp->right);
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
	binary_tree_t **queue = (binary_tree_t **) malloc(sizeof(binary_tree_t *) * Q_SIZE);

	*front = 0;
	*rear = 0;

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

void enqueue(binary_tree_t **queue, int *rear, const binary_tree_t *node)
{
	queue[*rear] = (binary_tree_t *)node;
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
	return (queue[(*front)++]);
}
