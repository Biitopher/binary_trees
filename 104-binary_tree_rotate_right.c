#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *new;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	node = tree->left;
	new = node->right;
	node->right = tree;
	tree->left = new;
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
