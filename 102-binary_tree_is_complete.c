#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of tree being checked
 * Return: 0 if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;
	queue_t *queue;
	const binary_tree_t *node;

	if (tree == NULL)
		return (0);

	queue = queue_create();
	if (queue == NULL)
		return (0);

	queue_push(queue, (void *)tree);
	while (!queue_is_empty(queue))
	{
		node = (const binary_tree_t *)queue_pop(queue);

		if (node == NULL)
			flag = 1;
		else
		{
			if (flag)
			{
				queue_delete(queue);
				return (0);
			}

			queue_push(queue, (void *)(node->left));
			queue_push(queue, (void *)(node->right));
		}
	}

	queue_delete(queue);
	return (1);
}
