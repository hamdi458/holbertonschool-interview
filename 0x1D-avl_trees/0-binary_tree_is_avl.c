#include "binary_trees.h"
/**
 * check_order - check order
 * @tree: the Pointer to root node being checked
 * @n: the Root node
 * @dir: the check values
 * Return: i or 0
 */

int check_order(const binary_tree_t *tree, int n, int dir)
{
	if (tree == NULL)
		return (1);

	if (tree->n < n || tree->n > dir)
		return (0);

	return (check_order(tree->left, n, tree->n - 1) &&
		check_order(tree->right, tree->n + 1, dir));
}
/**
 * bst_binary_tree - function that checks if valid is a
 * Binary search tree
 * @tree: Root of the tree
 * Return: 1 if the tree is BTS or 0 if not
 */

int best_binary_tree(const binary_tree_t *tree)
{
	return (check_order(tree, INT_MIN, INT_MAX));
}
/**
 * binary_tree_is_best - function that checks if valid is a
 * Binary search tree
 * @tree: Root of the tree
 * Return: 1 if valid BST, 0 if not or NULL
 */

int binary_tree_is_best(const binary_tree_t *tree)
{
	return (tree ? best_binary_tree(tree) : 0);
}
/**
 * binary_tree_height - calculates the height
 * @tree: node
 * Return: null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_avl - function that checks if a binary
 * tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t left_height, right_height, difference;

	if (tree == NULL)
		return (0);

	if (!binary_tree_is_best(tree))
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) : 0;
	right_height = tree->right ? binary_tree_height(tree->right) : 0;

	if (left_height > right_height)
		difference = left_height - right_height;
	else
		difference = right_height - left_height;

	if (difference > 1)
		return (0);

	if ((tree->left) == NULL && (tree->right) == NULL)
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}