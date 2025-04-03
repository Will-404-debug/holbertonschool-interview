#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Recursively builds the AVL tree from sorted array
 * @array: Pointer to the first element of the array
 * @start: Start index
 * @end: End index
 * @parent: Pointer to the parent node
 * Return: Pointer to the created node
 */
avl_t *create_avl_node(int *array, int start, int end, avl_t *parent)
{
    avl_t *node;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    node = binary_tree_node(parent, array[mid]);
    if (!node)
        return (NULL);

    node->left = create_avl_node(array, start, mid - 1, node);
    node->right = create_avl_node(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to root node of the AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (create_avl_node(array, 0, (int)size - 1, NULL));
}
