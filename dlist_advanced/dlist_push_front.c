#include <stddef.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
        return 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    new->data = element;
    new->prev = NULL;
    if (list->size == 0)
    {
        list->tail = new;
        new->next = NULL;
    }
    else
    {
        list->head->prev = new;
        new->next = list->head;
    }
    list->head = new;
    list->size += 1;
    return 1;
}
