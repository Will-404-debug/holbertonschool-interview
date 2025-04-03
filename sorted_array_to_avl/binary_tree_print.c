#include "binary_trees.h"
#include <stdio.h>

/* External helper */
static void print_tree(const binary_tree_t *tree, int level)
{
    if (tree == NULL)
        return;

    print_tree(tree->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("        ");
    printf("-> %d\n", tree->n);
    print_tree(tree->left, level + 1);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;
    print_tree(tree, 0);
}
