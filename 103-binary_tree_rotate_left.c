#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *new;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	node = tree->right;
	new = node->left;
	node->left = tree;
	tree->right = new;
	if (new != NULL)
		new->parent = tree;
	new = tree->parent;
	tree->parent = node;
	node->parent = new;
	if (new != NULL)
	{
		if (new->left == tree)
			new->left = node;
		else
			new->right = node;
	}

	return (node);
}
