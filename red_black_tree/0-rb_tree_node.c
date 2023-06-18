#include "rb_trees.h"

/**
 * rb_tree_node - a function that creates a Red-Black Tree node
 * @parent: pointer to the parent node
 * @value: the value to put in the new node
 * @color: the color of the node
 * Return: a pointer to the new node, or NULL on failure
 */

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node = malloc(sizeof(*node));

	if (node)
	{
		node->n = value;
		node->color = color;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
