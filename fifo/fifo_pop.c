#include <stdlib.h>

#include "fifo.h"

void fifo_pop(struct fifo *fifo)
{
    if (fifo)
    {
        if (fifo->size == 1)
        {
            free(fifo->head);
            fifo->head = NULL;
            fifo->tail = NULL;
            fifo->size -= 1;
        }
        else if (fifo->size == 2)
        {
            free(fifo->head);
            fifo->head = fifo->tail;
            fifo->size -= 1;
        }
        else if (fifo->size > 2)
        {
            struct list *temp = fifo->head;
            fifo->head = temp->next;
            free(temp);
            fifo->size -= 1;
        }
    }
}
