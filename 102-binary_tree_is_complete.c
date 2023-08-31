#include "binary_trees.h"
#include  "queue.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of tree being checked
 * Return: 0 if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int queue_size = 100;
	binary_tree_t *queue[queue_size];
	int front = 0, rear = 0;

	if (tree == NULL)
	{
		return (0);
	}

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (current == NULL)
		{
			while (front < rear && queue[front] == NULL)
			{
				front++;
			}
			if (front < rear)
			{
				return (0);
			}
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}

		if (rear >= queue_size)
		{
			return (-1);
		}
	}

	return (1);
}
