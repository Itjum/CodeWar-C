#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *new = malloc(sizeof(struct heap));
    new->size = 0;
    new->capacity = 8;
    new->array = malloc(sizeof(new->array) * 8);
    return new;
}
