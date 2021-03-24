#include "binary_trees.h"
#include <string.h>
#include <stdlib.h>


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: array to sort
 * @size: size of array
 * Return: pointer to avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	int mid = ((size / 2) - (size % 2) - 1);

	if (!array)
		return (NULL);

	tree = malloc(sizeof(avl_t));
	if (!tree)
		return (NULL);

	tree->parent = NULL;
	tree->n = array[mid];
	tree->right = avl_node(tree, array, mid + 1, size - 1);
	tree->left = avl_node(tree, array, 0, mid - 1);

	return (tree);
}

/**
 * avl_node - create new avl tree node
 * @tree: parent of node
 * @array: source array of integers
 * @start: beginning index from array
 * @end: ending index from array
 * Return: pointer to new node or NULL
 */
avl_t *avl_node(avl_t *tree, int *array, int start, int end)
{
	avl_t *node;
	int mid, size;

	size = (end - start);
	mid = (size / 2) + start;

	if (end < start)
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->parent = tree;
	node->n = array[mid];
	node->right = avl_node(node, array, mid + 1, end);
	node->left = avl_node(node, array, start, mid - 1);

	return (node);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: root node of tree to measure
 * Return: height or 0 if 0 or tree is null
 */
size_t tree_height(avl_t *tree)
{
	size_t h_l, h_r;

	if (tree)
	{
		h_l = (tree->left) ? tree_height(tree->left) + 1 : 0;
		h_r = (tree->right) ? tree_height(tree->right) + 1 : 0;

		return ((h_l >= h_r) ? h_l : h_r);
	}

	return (0);
}
