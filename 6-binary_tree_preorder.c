/**
 * binary_tree_preorder - Performs a preorder traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node, with the node's value as a parameter
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}
 
