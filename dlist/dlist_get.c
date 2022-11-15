#include "dlist.h"

int dlist_get(struct dlist *list, size_t index)
{
    if (index >= list->size)
    {
        return -1;
    }
    struct dlist_item *letsgo = list->head;
    size_t i = 0;
    while (i < index)
    {
        letsgo = letsgo->next;
        i++;
    }
    return letsgo->data;
}
