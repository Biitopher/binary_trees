#include "binary_trees.h"
/**
 * binary_tree_height - gets the height of the tree
 * @tree: Pointer to the tree
 * Return: Returns height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL)
		left_height = 0;
	else
		left_height = binary_tree_height(tree->left) + 1;

	if (tree->right == NULL)
		right_height = 0;
	else
		right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
