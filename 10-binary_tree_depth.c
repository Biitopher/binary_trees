#include "binary_trees.h"
/**
 * binary_tree_depth - Finds the depth of binary tree
 * @tree: Pointer to tree
 * Return: Returns the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *current = tree;

	if (tree == NULL)
		return (0);

	while (current->parent != NULL)
	{
		depth++;
		current = current->parent;
	}
	return (depth);
}
