#include "rb_trees.h"

/**
 * array_to_rb_tree - a function that builds a Binary Search Tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of elements in the array
 * Return: pointer
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i;
	rb_tree_t *new_tree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		rb_tree_insert(&new_tree, array[i]);

	return (new_tree);
}
