#include "binary_trees.h"

bst_t* find_min(bst_t* node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to root node of tree where you remove node
 * @value: value to remove from tree
 * Return: pointer to new node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
	{
		return (NULL);

		if (value < root->n)
		{
			root->left = bst_remove(root->left, value);
		}
		else if (value > root->n)
		{
			root->right = bst_remove(root->right, value);
		}
		else
		{
			if (root->left == NULL)
			{
				bst_t* temp = root->right;
				free(root);
				return (temp);
			}
			else if (root->right == NULL)
			{
				bst_t* temp = root->left;
				free(root);
				return (temp);
			}

			bst_t* temp = find_min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}

	}
	return (root);
}
