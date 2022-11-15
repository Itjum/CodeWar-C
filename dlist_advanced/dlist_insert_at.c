#include <stdlib.h>

#include "dlist.h"

int dlist_i_a(struct dlist *list, int element, size_t index)
{
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return -1;
    new->data = element;
    struct dlist_item *temp = list->head;
    struct dlist_item *temp2 = temp;
    size_t i = 0;
    while (i < index)
    {
        temp2 = temp;
        temp = temp->next;
        i++;
    }
    new->next = temp;
    new->prev = temp2;
    temp->prev = new;
    temp2->next = new;
    list->size += 1;
    return 1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (element < 0 || list == NULL || list->size < index)
        return -1;
    if (index == list->size)
    {
        return dlist_push_back(list, element);
    }
    else if (index == 0)
    {
        return dlist_push_front(list, element);
    }
    else
    {
        return dlist_i_a(list, element, index);
    }
}
