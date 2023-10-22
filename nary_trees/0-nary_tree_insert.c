#include "nary_trees.h"

/**
 * nary_tree_insert - a function that inserts a node in a N-ary tree.
 * @parent: is a pointer to the parent node.
 * @str:  is the string to be stored in the created node.
 * Return: a pointer to the created node, or NULL on failure.
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node;

	new_node = malloc(sizeof(nary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->content = strdup(str);
	new_node->parent = parent;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	if (new_node != NULL && parent)
	{
		parent->nb_children++;
		if (parent->children)
		{
			new_node->next = parent->children;
		}
		parent->children = new_node;
	}
	return (new_node);
}
