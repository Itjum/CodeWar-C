#include "dlist.h"

void dlist_sort(struct dlist *list)
{
    if (!list || list->size <= 1)
        return;
    size_t i = 0;
    while (i < list->size)
    {
        struct dlist_item *temp = list->head;
        size_t j = 0;
        while (j < list->size - i - 1)
        {
            if (temp->data > temp->next->data)
            {
                int data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = data;
            }
            temp = temp->next;
            j++;
        }
        i++;
    }
}
