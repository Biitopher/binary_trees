#include "binary_trees.h"

/**
 * depth - node depth
 * @node: node whose depth being checked
 * Return: node depth
 */


size_t depth(const binary_tree_t *node)
{
	size_t d = 0;

	while (node)
	{
		d++;
		node = node->parent;
	}
	return (d);
}



/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor otherwise NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first = depth(first);
	size_t depth_second = depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
