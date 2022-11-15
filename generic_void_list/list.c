#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *n = malloc(sizeof(struct list));
    if (!n)
    {
        return NULL;
    }
    n->data = malloc(data_size);
    if (!n->data)
        return NULL;
    memcpy(n->data, value, data_size);
    n->next = list;
    return n;
}

size_t list_length(struct list *list)
{
    size_t res = 0;
    if (!list)
        return res;
    res++;
    struct list *tmp = list;
    while (tmp->next)
    {
        tmp = tmp->next;
        res++;
    }
    return res;
}

void list_destroy(struct list *list)
{
    if (!list)
        return;
    struct list *temp = list;
    while (list->next)
    {
        temp = list->next;
        free(list->data);
        free(list);
        list = temp;
    }
    free(list->data);
    free(list);
}
