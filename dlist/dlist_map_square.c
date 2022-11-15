#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    size_t i = 0;
    if (list == NULL)
        return;
    struct dlist_item *temp = list->head;
    while (i < list->size)
    {
        temp->data *= temp->data;
        temp = temp->next;
        i++;
    }
}
