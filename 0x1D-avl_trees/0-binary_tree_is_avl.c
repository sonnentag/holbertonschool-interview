#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: height of tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l, h_r;

	if (!tree)
		return (0);

	h_l = (tree->left) ? binary_tree_height(tree->left) + 1 : 0;
	h_r = (tree->right) ? binary_tree_height(tree->right) + 1 : 0;

	return ((h_l >= h_r) ? h_l : h_r);
}

/**
 * binary_tree_is_bst - check if avl tree is bst and root node is balanced
 * @tree: pointer to root node of tree to check
 * Return: 1 if true or else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree, int max)
{
	if (tree->left != NULL && (tree->left->n > tree->n || tree->left->n > max))
		return (0);

	if (tree->right != NULL && (tree->right->n < tree->n || tree->right->n < max))
		return (0);

	if (tree->left)
		if (binary_tree_is_bst(tree->left, max) == 0)
			return (0);

	if (tree->right)
		if (binary_tree_is_bst(tree->right, max) == 0)
			return (0);

	return (1);
}

/**
 * binary_tree_is_avl - find the balance of an AVL tree
 * @tree: pointer to the tree
 * Return: 1 if true or else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance = 0;
  int max;

	if (!tree)
		return (0);

  max = tree->n;

	if ((!tree->left) && (!tree->right))
		return (1);

	if (binary_tree_is_bst(tree, max) == 0)
		return (0);

	if (tree->left)
		balance += binary_tree_height(tree->left);

	if (tree->right)
		balance -= binary_tree_height(tree->right);

	return (balance == 0 ? 1 : 0);
}
