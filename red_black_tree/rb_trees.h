#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <stdio.h>
#include <stdlib.h>


/**
 * enum rb_color_e - possible red-black tree colors
 *
 * @RED: 0 -> red node
 * @BLACK: 1 -> black node
 * @DOUBLE_BLACK: 2 -> double-black node (used for deletion)
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;


/**
 * struct rb_tree_s - red-black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: pointer to the parent node
 * @left: pointer to the left child node
 * @right: pointer to the right child node
 * @color: color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

void rb_tree_print(const rb_tree_t *tree);

/* rb_tree_node.c */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);

/* rb_tree_is_valid.c */
int rb_tree_is_valid(const rb_tree_t *tree);
int bst(const rb_tree_t *tree, int min, int max);
int colors(const rb_tree_t *tree);
int f_height(const rb_tree_t *tree);
int crb_height(const rb_tree_t *tree, int blk_height, int height);


#endif /* _RB_TREES_H_ */
