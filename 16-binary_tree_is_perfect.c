#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Checks if tree is perfect
 * @tree: Pointer to tree
 * Return: Returns 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, perfect_size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	perfect_size = (1 << height) - 1;

	return (size == perfect_size);
}

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

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

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
