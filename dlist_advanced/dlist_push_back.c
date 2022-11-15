#include <stddef.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    new->data = element;
    new->next = NULL;
    if (list->size == 0)
    {
        list->head = new;
        new->prev = NULL;
    }
    else
    {
        list->tail->next = new;
        new->prev = list->tail;
    }
    list->tail = new;
    list->size += 1;
    return 1;
}
