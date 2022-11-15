#include "fifo.h"

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}
