#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

#define Q_SIZE 500

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Queue prototypes */
binary_tree_t **create_queue(int *front, int *rear);
binary_tree_t *dequeue(binary_tree_t **queue, int *front);
void enqueue(binary_tree_t **queue, int *rear, const binary_tree_t *node);

void binary_tree_delete(binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

#endif /*BINARY_TREES_H*/
