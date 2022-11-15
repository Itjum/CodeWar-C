#include <stdlib.h>

#include "dlist.h"

int dlist_remove_eq(struct dlist *list, int element)
{
    if (list == NULL || list->size == 0 || element < 0)
        return 0;
    else if (list->size == 1)
    {
        if (list->head->data == element)
        {
            int r = dlist_remove_at(list, 0);
            if (r == -1)
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
    {
        size_t i = 0;
        struct dlist_item *temp = list->head;
        while (i < list->size && temp && element != temp->data)
        {
            temp = temp->next;
            i++;
        }
        if (i == list->size)
            return 0;
        int r = dlist_remove_at(list, i);
        if (r <= 0)
            return 0;
        return 1;
    }
}
