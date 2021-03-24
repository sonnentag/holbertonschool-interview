#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *tree);

/* 0 */
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_node(avl_t *tree, int *array, int start, int end);
avl_t *insert_node(avl_t *tree, avl_t *node);

#endif /* _BINARY_TREES_H */
