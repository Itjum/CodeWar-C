#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_split_base(struct dlist *list, struct dlist *new)
{
    new->head = list->head;
    new->tail = list->tail;
    new->size = list->size;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return new;
}

struct dlist *dlist_split_tail(struct dlist *list, struct dlist *new)
{
    struct dlist_item *temp = list->tail;
    new->head = list->tail;
    new->tail = list->tail;
    new->size = 1;
    list->tail = temp->prev;
    list->tail->next = NULL;
    list->size -= 1;
    return new;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    struct dlist *new = dlist_init();
    if (!list || (index >= list->size && list->size != 0) || new == NULL)
    { // la ligne au dessus a ete modifie (list->size != 0)
        free(new);
        return NULL;
    }
    else if (list->size == 0) // ces deux lignes sont nouvelles
    {
        return new;
    }
    else if (index == 0)
    {
        return dlist_split_base(list, new);
    }
    else if (index == list->size - 1)
    {
        return dlist_split_tail(list, new);
    }
    size_t i = 0;
    struct dlist_item *temp = list->head;
    struct dlist_item *temp2 = temp;
    while (i < index)
    {
        temp2 = temp;
        temp = temp->next;
        i++;
    }
    temp2->next = NULL;
    temp->prev = NULL;
    new->head = temp;
    new->tail = list->tail;
    new->size = list->size - index;
    list->size -= new->size;
    list->tail = temp2; // added this
    return new;
}
