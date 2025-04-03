#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl - Recursively builds an AVL tree from sorted array
 * @array: pointer to the first element
 * @start: starting index
 * @end: ending index
 * @parent: pointer to parent node
 *
 * Return: pointer to root node or NULL
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    root = malloc(sizeof(avl_t));
    if (!root)
        return (NULL);

    root->n = array[mid];
    root->parent = parent;
    root->left = create_avl(array, start, mid - 1, root);
    root->right = create_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: pointer to first element
 * @size: number of elements
 *
 * Return: pointer to root node, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (create_avl(array, 0, size - 1, NULL));
}
