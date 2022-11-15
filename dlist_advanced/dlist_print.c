#include <stdio.h>

#include "dlist.h"

void dlist_print(const struct dlist *list)
{
    if (list)
    {
        if (list->head)
        {
            struct dlist_item *tmp = list->head;
            size_t i = 0;
            while (i < list->size)
            {
                printf("%d\n", tmp->data);
                tmp = tmp->next;
                i++;
            }
        }
    }
}
