#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through binary tree level-order traversal
 * @tree: pointer to root node the tree is to traverse
 * @func: pointer to function call each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

