#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right-child of another node
 * @parent: pointer to parent node to the right-child
 * @value: New node value
 * Return: new node on success otherwise NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t *new_node;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	return (new_node);
}
