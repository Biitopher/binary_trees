#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to node created otherwise NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = *tree;
	bst_t *new_node = malloc(sizeof(bst_t));

	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	while (current)
	{
		if (value == current->n)
		{
			free(new_node);
			return (NULL);
		}
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}
	return (NULL);
}
