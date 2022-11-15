#include <stdlib.h>

#include "dlist.h"

int dlist_remove_head(struct dlist *list)
{
    struct dlist_item *temp = list->head;
    list->head = temp->next;
    temp->next->prev = NULL;
    temp->next = NULL;
    list->size -= 1;
    int data = temp->data;
    free(temp);
    return data;
}

int dlist_remove_tail(struct dlist *list)
{
    struct dlist_item *temp = list->tail;
    list->tail = temp->prev;
    temp->prev->next = NULL;
    temp->prev = NULL;
    list->size -= 1;
    int data = temp->data;
    free(temp);
    return data;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (!list || index >= list->size)
        return -1;
    else if (list->size == 1 && index == 0)
    {
        int data = list->head->data;
        list->size -= 1;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return data;
    }
    else if (index == 0)
    {
        return dlist_remove_head(list);
    }
    else if (index == list->size - 1)
    {
        return dlist_remove_tail(list);
    }
    else
    {
        struct dlist_item *temp = list->head;
        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        int data = temp->data;
        free(temp);
        list->size -= 1;
        return data;
    }
}
