#include "dlist.h"

void shift_list(struct dlist *list, int shift)
{
    struct dlist_item *temp1 = list->head;
    struct dlist_item *temp2 = list->tail;
    temp2->next = temp1;
    temp1->prev = temp2;
    int c = 0;
    while (c < shift)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        c++;
    }
    temp1->prev = NULL;
    list->head = temp1;
    temp2->next = NULL;
    list->tail = temp2;
}

void shift_list2(struct dlist *list, int shift)
{
    struct dlist_item *temp1 = list->head;
    struct dlist_item *temp2 = list->tail;
    temp2->next = temp1;
    temp1->prev = temp2;
    int c = 0;
    while (c < shift)
    {
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        c++;
    }
    temp1->prev = NULL;
    list->head = temp1;
    temp2->next = NULL;
    list->tail = temp2;
}

void dlist_shift(struct dlist *list, int offset)
{
    if (list && list->size > 1 && offset != 0)
    {
        int shift = offset;
        if (offset < 0)
        {
            shift = list->size - offset;
            while (shift < 0)
            {
                shift -= offset;
            }
            shift_list(list, shift);
        }
        else if (offset > 0)
        {
            shift_list2(list, offset);
        }
    }
}
