#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/* Printing helper functions */
void binary_tree_print(const binary_tree_t *tree)
{
    static int depth = 0;
    if (tree == NULL)
        return;

    depth++;
    binary_tree_print(tree->right);

    printf("%*s%d\n", depth * 4, "", tree->n);

    binary_tree_print(tree->left);
    depth--;
}
