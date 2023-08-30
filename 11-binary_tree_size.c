#include "binary_trees.h"
/**
 * binary_tree_size - Finds the size of the tree
 * @tree: Pointer to tree
 * Return: Returns the size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
