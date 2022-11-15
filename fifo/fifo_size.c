#include <stddef.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    size_t res = 0;
    if (fifo)
    {
        struct list *temp = fifo->head;
        while (temp)
        {
            res++;
            temp = temp->next;
        }
    }
    return res;
}
