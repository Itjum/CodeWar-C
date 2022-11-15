#include <stdlib.h>

#include "fifo.h"

void fifo_push(struct fifo *fifo, int elt)
{
    if (fifo)
    {
        struct list *new = malloc(sizeof(struct list));
        if (new)
        {
            new->data = elt;
            if (fifo->head)
                new->next = fifo->head;
            else
            {
                new->next = NULL;
                fifo->tail = new;
            }
            fifo->head = new;
            fifo->size += 1;
        }
    }
}
