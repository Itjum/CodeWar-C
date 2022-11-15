#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *new = malloc(sizeof(struct fifo));
    new->size = 0;
    new->head = NULL;
    new->tail = NULL;
    return new;
}
