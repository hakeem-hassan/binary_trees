#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: tree to be checked
 *
 * Return: 1 if complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	int front, rear, flag = 0;
	const binary_tree_t *node;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	queue = create_queue(&front, &rear);
	enqueue(queue, &rear, tree);

	while (front < rear)
	{
		node = dequeue(queue, &front);

		if (node == NULL)
			flag = 1;

		else
		{
			if (flag == 1)
			{
				free(queue);
				return (0);
			}
			enqueue(queue, &rear, node->left);
			enqueue(queue, &rear, node->right);
		}
	}

	free(queue);
	return (1);
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
