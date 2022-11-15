#include "dlist.h"

struct dlist *dlist_copy(const struct dlist *list)
{
    if (list == NULL)
        return NULL;
    if (list->size == 0)
    {
        return dlist_init();
    }
    struct dlist *new = dlist_init();
    if (!new)
        return NULL;
    struct dlist_item *temp = list->head;
    dlist_push_front(new, temp->data);
    size_t i = 1;
    while (i < list->size)
    {
        temp = temp->next;
        i++;
        dlist_push_back(new, temp->data);
    }
    return new;
}
