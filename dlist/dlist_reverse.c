#include <stdlib.h>

#include "dlist.h"

void dlist_reverse(struct dlist *list)
{
    if (list == NULL || list->size == 0 || list->size == 1)
        return;
    struct dlist_item *temp = NULL;
    struct dlist_item *curr = list->head;
    list->tail = curr;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        list->head = temp->prev;
    }
}
