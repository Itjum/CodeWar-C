#include <stdio.h>

#include "fifo.h"

void fifo_print(const struct fifo *fifo)
{
    if (fifo)
    {
        if (fifo->size > 0)
        {
            struct list *temp = fifo->head;
            while (temp)
            {
                printf("%d\n", temp->data);
                temp = temp->next;
            }
        }
    }
}
