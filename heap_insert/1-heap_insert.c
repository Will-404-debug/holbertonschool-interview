#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_up - Restores the Max Heap property after insertion
 * @node: Pointer to the inserted node
 *
 * Return: Pointer to the inserted node after heapify
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    return (node);
}

/**
 * find_insert_position - Finds the next position for a new node in level order
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
heap_t *find_insert_position(heap_t *root)
{
    heap_t *queue[1024];
    int front = 0, back = 0;

    queue[back++] = root;

    while (front < back)
    {
        heap_t *current = queue[front++];

        if (!current->left || !current->right)
            return (current);

        queue[back++] = current->left;
        queue[back++] = current->right;
    }

    return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    parent = find_insert_position(*root);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (heapify_up(new_node));
}
