#include "binary_trees.h"

bst_t *bst_find_min(bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, int value);

bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    return bst_remove_recursive(root, value);
}

bst_t *bst_remove_recursive(bst_t *root, int value)
{
	bst_t *temp;

    if (root == NULL)
        return root;

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
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        temp = bst_find_min(root->right);

        root->n = temp->n;
        root->right = bst_remove_recursive(root->right, temp->n);
    }

    return root;
}

bst_t *bst_find_min(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}
