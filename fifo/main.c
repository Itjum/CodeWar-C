#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

int main(void)
{
    // tests
    struct fifo *a = fifo_init();
    printf("size: %lu \n", fifo_size(a));
    fifo_push(a, 1);
    fifo_push(a, 3);
    fifo_push(a, 6);
    fifo_push(a, 9);
    printf("size: %lu \n", fifo_size(a));
    printf("fifo head: %d\n", fifo_head(a));
    printf("full queue: \n");
    fifo_print(a);
    fifo_pop(a);
    printf("fifo head after pop: %d\n", fifo_head(a));
    fifo_destroy(a);
}
