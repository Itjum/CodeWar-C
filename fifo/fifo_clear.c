#include "fifo.h"

void fifo_clear(struct fifo *fifo)
{
    if (!fifo || fifo->size == 0)
        return;
    struct list *temp = fifo->head;
    while (temp)
    {
        fifo_pop(fifo);
        temp = fifo->head;
    }
}
