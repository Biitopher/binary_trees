#include "binary_trees.h"

/**
 * is_bst_helper - checks whether each node in tree satisfies the properties
 * @node: nodes with values
 * @min_val: minimum range
 * @max_val: maximum range
 * Return: True on success false on fail
 */

bool is_bst_helper(const binary_tree_t *node, int min_val, int max_val)
{
	if (node == NULL)
	{
		return (true);
	}

	if (node->n <= min_val || node->n >= max_val)
	{
		return (false);
	}

	return (is_bst_helper(node->left, min_val, node->n) &&
			is_bst_helper(node->right, node->n, max_val));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * @tree: pointer to root node of tree being checked
 * Return: 1 on success 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
