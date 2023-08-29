#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through binary tree using post-order traversal
 * @pointer to the root node of the tree to traverse
 * @func: pointer to function call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);

	func(tree->n);
}