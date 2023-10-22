#include "nary_trees.h"
/**
 * path_exists - a function that checks if a path exists in an N-ary tree.
 * @root: is a pointer to the root node of the tree
 * @path: is a NULL terminated array of strings
 * Return: 0 or 1
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t i;

	if (!root || !path || !*path)
		return (0);
	for (i = 0; path[i]; ++i, root = root->children)
	{
		while (root && strcmp(root->content, path[i]) != 0)
			root = root->next;
		if (root == NULL)
			return (0);
	}
	return (1);
}
