#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *new = malloc(sizeof(struct bst));
    if (!new)
        return NULL;
    new->capacity = capacity;
    new->size = 0;
    new->data = malloc(sizeof(new->data) * capacity);
    if (!new->data)
        return NULL;
    for (size_t i = 0; i < capacity; i++)
        new->data[i] = NULL;
    return new;
}

void add(struct bst *tree, int value)
{
    size_t i = 0;
    if (tree)
    {
        while (i < tree->capacity)
        {
            if (tree->data[i] == NULL)
            {
                struct value *v = malloc(sizeof(struct value));
                v->val = value;
                tree->size += 1;
                tree->data[i] = v;
                return;
            }
            else
            {
                if (tree->data[i]->val > value)
                    i = 2 * i + 1;
                else
                    i = 2 * i + 2;
            }
        }

        if (i >= tree->capacity)
        {
            size_t j = tree->capacity;
            size_t mem = tree->capacity * 2 + 1;
            tree->capacity = mem;
            tree->data = realloc(tree->data, sizeof(struct value *) * mem);
            for (; j < mem; j++)
                tree->data[j] = NULL;
            add(tree, value);
        }
    }
}

int search(struct bst *tree, int value)
{
    size_t i = 0;
    if (tree == NULL || tree->data == NULL || tree->size == 0)
    {
        return -1;
    }
    while (i < tree->capacity && tree->data[i])
    {
        if (tree->data[i]->val == value)
            return i;
        if (tree->data[i]->val > value)
        {
            i = 2 * i + 1;
        }
        else
            i = 2 * i + 2;
    }
    return -1;
}

void bst_free(struct bst *tree)
{
    if (tree == NULL)
        return;
    size_t i = 0;
    while (i < tree->capacity)
    {
        if (tree->data[i])
        {
            free(tree->data[i]);
        }
        i++;
    }
    free(tree->data);
    free(tree);
}
