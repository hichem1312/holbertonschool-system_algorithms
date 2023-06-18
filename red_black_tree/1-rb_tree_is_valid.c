#include "rb_trees.h"

/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is valid, otherwise 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	if (tree->color != BLACK)
		return (0);

	if (!bst(tree, 0, 0))
		return (0);

	if (!colors(tree))
		return (0);

	height = f_height(tree);

	if (!crb_height(tree, height, 0))
		return (0);

	return (1);
}

/**
 * bst - checks if A Red-Black Tree is a BST
 * @tree: a binary tree
 * @min: minimum
 * @max: maximum
 * Return: 1 or 0
 */
int bst(const rb_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if ((min && tree->n < min) || (max && tree->n > max))
		return (0);

	return (bst(tree->left, 0, tree->n) &&
		 bst(tree->right, tree->n, 0));
}

/**
 * colors - checks if RBT has valid colors
 * @tree: a binary tree
 * Return: 1 or 0
 */
int colors(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED)
	{
		if (tree->left && (tree->left)->color == RED)
			return (0);
		if (tree->right && (tree->right)->color == RED)
			return (0);
	}
	return (colors(tree->left) && colors(tree->right));
}

/**
 * f_height - gets height of rb tree
 * @tree: binary tree
 * Return: maximum of black nodes between root and leaf
 */
int f_height(const rb_tree_t *tree)
{
	int i = 0, j = 0;

	if (tree == NULL || (!tree->right && !tree->left))
	    return (0);
	i = f_height(tree->left);
	j = f_height(tree->right);

	if (i >= j)
		return (i + 1);
    
    return (j + 1);
}

/**
 * crb_height - finds the height of black nodes in RBT
 *
 * @tree: tree to check
 * @black_height: number of black nodes
 * @height: max height
 *
 * Return: 1 if yes, 0 if no
 */
int crb_height(const rb_tree_t *tree, int black_height, int height)
{
	if (!tree)
	{
		if (height == black_height)
			return (1);
		return (0);
	}
	if (tree->color == BLACK)
		height++;

	return (crb_height(tree->left, black_height, height) &&
		crb_height(tree->right, black_height, height));
}