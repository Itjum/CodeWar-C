#include "dlist.h"

int dlist_find(const struct dlist *list, int element)
{
    if (list == NULL || element < 0)
        return -1;
    size_t i = 0;
    struct dlist_item *temp = list->head;
    if (temp->data == element)
        return 0;
    while (i < list->size)
    {
        if (temp->data == element)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}
