#include "binary_trees.h"
/**
 * binary_tree_uncle - Finds uncle to a node
 * @node: Node
 * Return: The uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent = node->parent->parent;

	if (node == NULL || node->parent == NULL || grandparent == NULL)
		return (NULL);

	if (grandparent->left == node->parent)
		return (grandparent->right);
	return (grandparent->left);
}
