#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - create new binary tree node
 * @parent: parent of node
 * @value: number stored in node
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
