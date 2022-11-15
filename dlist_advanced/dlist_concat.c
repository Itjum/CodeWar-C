#include <stdlib.h>

#include "dlist.h"

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list2->size == 0)
        return;
    struct dlist_item *temp = list1->tail;
    struct dlist_item *temp2 = list2->head;
    temp->next = temp2;
    temp2->prev = temp;
    list1->size += list2->size;
    list1->tail = list2->tail; // added this
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
