#include "rb_trees.h"

/**
 * rb_tree_insert - a function that inserts a value in a Red-Black Tree
 * @tree: is a double pointer to the root node of the Red-Black tree
 * @value: is the value to store in the node to be inserted
 * Return: pointer
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *a = NULL;
	rb_tree_t *b = NULL;
	rb_tree_t *new_node = NULL;

	if (!tree)
		return (NULL);

	a = *tree;
	while (a != NULL)
	{
		b = a;
		if (a->n == value)
			return (NULL);
		if (value < a->n)
			a = a->left;
		else if (value > a->n)
			a = a->right;
	}
	new_node = rb_tree_node(b, value, RED);
	if (!new_node)
		return (NULL);

	if (b == NULL)
		*tree = new_node;
	else if (new_node->n < b->n)
		b->left = new_node;
	else
		b->right = new_node;
	insert_fixup(tree, new_node);
	return (new_node);
}

/**
 * insert_fixup - insert fixup
 * @tree: pointer
 * @new_node: new node
 */
void insert_fixup(rb_tree_t **tree, rb_tree_t *new_node)
{
	while (new_node->parent && new_node->parent->color == RED)
	{
		if (new_node->parent->parent && new_node->parent == new_node->parent->parent->left)
			new_node = insert_RIGHT_fixup(tree, new_node);
		else
			new_node = insert_LEFT_fixup(tree, new_node);
	}
	(*tree)->color = BLACK;
}

/**
 * insert_LEFT_fixup - left fixup
 * @tree: pointer
 * @new_node: new node
 * Return: pointer
 */
rb_tree_t *insert_LEFT_fixup(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *b = NULL;

	b = new_node->parent->parent->left;
	if (b && b->color == RED)
	{
		new_node->parent->color = BLACK;
		b->color = BLACK;
		new_node->parent->parent->color = RED;
		new_node = new_node->parent->parent;
	}
	else
	{
		if (new_node == new_node->parent->left)
		{
			new_node = new_node->parent;
			right_rotate(tree, new_node);
		}
		new_node->parent->color = BLACK;
		new_node->parent->parent->color = RED;
		left_rotate(tree, new_node->parent->parent);
	}
	return (new_node);
}

/**
 * insert_RIGHT_fixup - right fixup
 * @tree: node
 * @new_node: new_node
 * Return: pointer
 */
rb_tree_t *insert_RIGHT_fixup(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *b = NULL;

	b = new_node->parent->parent->right;
	if (b && b->color == RED)
	{
		new_node->parent->color = BLACK;
		b->color = BLACK;
		new_node->parent->parent->color = RED;
		new_node = new_node->parent->parent;
	}
	else
	{
		if (new_node == new_node->parent->right)
		{
			new_node = new_node->parent;
			left_rotate(tree, new_node);
		}
		new_node->parent->color = BLACK;
		new_node->parent->parent->color = RED;
		right_rotate(tree, new_node->parent->parent);
	}
	return (new_node);
}

/**
 * left_rotate - rotate
 * @tree: node
 * @r: rotate
 */
void left_rotate(rb_tree_t **tree, rb_tree_t *r)
{
	rb_tree_t *b = NULL;

	b = r->right;
	r->right = b->left;
	if (b->left)
		b->left->parent = r;
	b->parent = r->parent;
	if (r->parent == NULL)
		*tree = b;
	else if (r == r->parent->left)
		r->parent->left = b;
	else
		r->parent->right = b;
	b->left = r;
	r->parent = b;
}

/**
 * right_rotate - rotate
 * @tree: node
 * @r: rotate
 */
void right_rotate(rb_tree_t **tree, rb_tree_t *r)
{
	rb_tree_t *b = NULL;

	b = r->left;
	r->left = b->right;
	if (b->right)
		b->right->parent = r;
	b->parent = r->parent;
	if (r->parent == NULL)
		*tree = b;
	else if (r == r->parent->left)
		r->parent->left = b;
	else
		r->parent->right = b;
	b->right = r;
	r->parent = b;
}