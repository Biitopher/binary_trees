#include "binary_trees.h"
/**
 * binary_tree_nodes - Finds nodes with atleast 1 child
 * @tree: Pointer to the tree
 * Return: Returns number of nodes with atleast 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		left_nodes = binary_tree_nodes(tree->left);
		right_nodes = binary_tree_nodes(tree->right);

		return (left_nodes + right_nodes + 1);
	}

	return (0);
}
