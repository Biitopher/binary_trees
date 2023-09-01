#include "binary_trees.h"

bst_t *bst_find_min(bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, int value);

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to root node of tree where you remove node
 * @value: value to remove from tree
 * Return: pointer to new node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	return (bst_remove_recursive(root, value));
}

/**
 * bst_remove_recursive - removes a node from a Binary Search Tree recursively
 * @root: pointer to root node of tree where you remove node
 * @value: value to remove from tree
 * Return: pointer to new node
 */
bst_t *bst_remove_recursive(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
	{
		root->left = bst_remove_recursive(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove_recursive(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_find_min(root->right);

		root->n = temp->n;
		root->right = bst_remove_recursive(root->right, temp->n);
	}

	return (root);
}

/**
 * bst_find_min - finds minimum value
 * @node: node being searched
 * Return: node on success
 */
bst_t *bst_find_min(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
	{
		current = current->left;
	}

	return (current);
}
