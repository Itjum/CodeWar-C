#include "bst.h"

#include <stddef.h>
#include <stdlib.h>

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
    if (value < tree->data)
        tree->left = add_node(tree->left, value);
    else if (value > tree->data)
        tree->right = add_node(tree->right, value);
    return tree;
}

struct bst_node *max_value_node(struct bst_node *node)
{
    struct bst_node *new = node;
    while (new && (new->right != NULL))
    {
        new = new->right;
    }
    return new;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    if (value > tree->data)
        tree->right = delete_node(tree->right, value);
    else if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else
    {
        if (tree->left == NULL)
        {
            struct bst_node *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            struct bst_node *temp = tree->left;
            free(tree);
            return temp;
        }
        struct bst_node *temp = max_value_node(tree->left);
        tree->data = temp->data;
        tree->left = delete_node(tree->left, temp->data);
    }
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    if (value == tree->data)
        return tree;
    else if (value < tree->data)
        return find(tree->left, value);
    else
        return find(tree->right, value);
}

void free_bst(struct bst_node *tree)
{
    if (tree == NULL)
        return;
    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
}
