#include <stdlib.h>

#include "fifo.h"

void fifo_destroy(struct fifo *fifo)
{
    if (fifo)
    {
        fifo_clear(fifo);
        free(fifo);
    }
}
