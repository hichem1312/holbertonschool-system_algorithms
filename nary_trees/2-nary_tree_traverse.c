#include "nary_trees.h"

/**
 * nary_tree_traverse - function that goes through an N-ary tree, node by node
 * @root: is a pointer to the root node of the tree to traverse
 * @action: is a pointer to a function to execute for each node being traversed
 * Return: the biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth))
{
    size_t i;
	static size_t depth, max;

	while (root != NULL)
	{
		action(root, depth);
		++depth;
		nary_tree_traverse(root->children, action);
		root = root->next;
	}
	if (max < depth)
    {
		max = depth;
    }
	if (depth == 0)
	{
		i = max;
		max = 0;
	}
	else
    {
		--depth;
    }
	return (i);
}
