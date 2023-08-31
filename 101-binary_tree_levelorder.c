#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - goes through binary tree level-order traversal
 * @tree: pointer to root node the tree is to traverse
 * @func: pointer to function call each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		node = (const binary_tree_t *)queue_pop(queue);
		func(node->n);

		if (node->left != NULL)
			queue_push(queue, (void *)(node->left));
		if (node->right != NULL)
			queue_push(queue, (void *)(node->right));
	}

	queue_delete(queue);
}
