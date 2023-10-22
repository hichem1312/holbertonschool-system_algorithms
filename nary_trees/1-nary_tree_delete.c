#include "nary_trees.h"

/**
 * nary_tree_delete - a function that deallocates an entire N-ary tree
 * @tree: tree
 * Return: nothing
 */

void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *node_1, *node_2;

	if (!tree)
		return;
	node_1 = tree->children;
	while (node_1 != NULL)
	{
		node_2 = node_1->next;
		nary_tree_delete(node_1);
		node_1 = node_2;
	}
	free(tree->content);
	free(tree);
}
