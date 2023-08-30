#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of tree being checked
 * Return: 0 if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	int isComplete = 1;

	binary_tree_t **queue = queue;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * 1000);
	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		if (node == NULL)
		{
			isComplete = 0;
		}
		else
		{
			queue[rear++] = node->left;
			queue[rear++] = node->right;
		}
	}
	while (rear > 0 && queue[rear - 1] == NULL)
	{
		rear--;
	}
	if (rear > 0)
	{
		isComplete = 0;
	}
	free(queue);
	return (isComplete);
}
