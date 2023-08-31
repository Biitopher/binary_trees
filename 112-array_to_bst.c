#include "binary_trees.h"

/**
 * array_to_bst - Create bst from array
 * @array: Array to be used
 * @size: Size of array
 * Return: Returns the root of the tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}
