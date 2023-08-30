#include "binary_trees.h"

/**
 * enqueue - Adds node at the front of the order
 * @rear: pointer to where the node is to be added
 * @node: node to be added
 */

void enqueue(queue_node_t **rear, const binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (!new_node)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (*rear == NULL)
	{
		*rear = new_node;
	}
	else
	{
		(*rear)->next = new_node;
		*rear = new_node;
	}
}


/**
 * dequeue - removes node fron the order
 * @front: node at the front for removal
 * Return: node on success otherwise NULL
 */

const binary_tree_t *dequeue(queue_node_t **front)
{
	const binary_tree_t *node = (*front)->node;
	queue_node_t *temp = *front;

	if (*front == NULL)
		return (NULL);

	*front = (*front)->next;
	free(temp);
	return (node);
}


/**
 * binary_tree_levelorder - goes through binary tree level-order traversal
 * @tree: pointer to root node the tree is to traverse
 * @func: pointer to function call each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	queue_node_t *front = NULL;
	queue_node_t *rear = NULL;

	enqueue(&rear, tree);

	while (front != NULL)
	{
		const binary_tree_t *node = dequeue(&front);

		func(node->n);

		if (node->left)
			enqueue(&rear, node->left);
		if (node->right)
			enqueue(&rear, node->right);
	}
}
