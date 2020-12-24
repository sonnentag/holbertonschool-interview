#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const heap_t *);

/* 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1 */
heap_t *heap_insert(heap_t **root, int value);
heap_t *find_last(heap_t *root);
size_t tree_size(const heap_t *tree);
size_t tree_height(const heap_t *tree);

#endif /* _BINARY_TREES_H_ */
