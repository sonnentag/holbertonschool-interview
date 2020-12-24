#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - insert into max heap binary tree
 * @root: root of tree
 * @value: number to insert
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new;
	int temp;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_last(*root);
	new = binary_tree_node(parent, value);

	(parent->left == NULL) ? (parent->left = new) : (parent->right = new);

	while (parent->n < new->n)
	{
		temp = parent->n;
		parent->n = new->n;
		new->n = temp;

		new = parent;

		if (parent->parent)
			parent = parent->parent;
	}

	return (new);
}

/**
 * find_last - find next available position to add node
 * @root: root of tree
 * Return: pointer to new parent node
 */
heap_t *find_last(heap_t *root)
{
	if (tree_size(root) % 2 == 0)
		while (root->right && root->left)
		{
			if (tree_height(root->left) == tree_height(root->right))
				return (find_last(root->right));
			else
				return (find_last(root->left));
		}
	else
		while (root->right || root->left)
		{
			if (tree_height(root->left) != tree_height(root->right) && (root->right))
				return (find_last(root->right));
			else
				return (find_last(root->left));
		}

	return (root);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: root node of tree to measure
 * Return: height or 0 if 0 or tree is null
 */
size_t tree_height(const heap_t *tree)
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

/**
 * tree_size - measures the size of a binary tree
 * @tree: root node of tree to measure
 * Return: size or 0 if 0 or tree is null
 */
size_t tree_size(const heap_t *tree)
{
	size_t s = 0, s1 = 0, s2 = 0;

	if (tree)
	{
		s1 = tree_size(tree->left);
		s2 = tree_size(tree->right);
		s = s1 + s2;

		return (s + 1);
	}

	return (0);
}
