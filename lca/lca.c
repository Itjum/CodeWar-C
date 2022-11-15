#include "lca.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*int lca2(int *values, int i, int p, int q)
{
    int i1 = 2 * i + 1;
    int i2 = 2 * i + 2;
    if (values[i] > p && values[i] > q)
    {
        return lca2(values, i1, p, q);
    }
    if (values[i] < p && values[i] < q)
    {
        return lca2(values, i2, p, q);
    }
    return values[i];
}*/

void print_bst(struct bst_node *root)
{
    if (!root)
    {
        return;
    }
    printf("%d ", root->data);
    print_bst(root->left);
    print_bst(root->right);
}

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return create_node(value);
    if (!tree->left
    if (value < tree->data)
        tree->left = add_node(tree->left, value);
    else if (value > tree->data)
        tree->right = add_node(tree->right, value);
    return tree;
}

void free_bst(struct bst_node *tree)
{
    if (tree == NULL)
        return;
    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}

struct bst_node *lca2(struct bst_node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return lca2(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca2(root->right, n1, n2);
    return root;
}

int lca(int *values, int length, int p, int q)
{
    if (length == 1)
    {
        return values[0];
    }
    else
    {
        struct bst_node *new = create_node(values[0]);
        int i = 1;
        while (i < length)
        {
            new = add_node(new, values[i]);
            i++;
        }
        struct bst_node *res = lca2(new, p, q);
        print_bst(new);
        return (res->data);
    }
}
