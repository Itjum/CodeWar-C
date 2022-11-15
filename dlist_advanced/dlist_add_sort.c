#include "dlist.h"

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;
    if (list->size == 0)
    {
        int t = dlist_push_front(list, element);
        if (t == 0)
            return -1;
        return 1;
    }
    else
    {
        size_t i = 0;
        struct dlist_item *temp = list->head;
        while (i < list->size && temp->data < element)
        {
            temp = temp->next;
            i++;
        }
        return dlist_insert_at(list, element, i);
    }
}
