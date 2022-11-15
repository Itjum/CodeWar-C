#include <stdlib.h>

#include "vector.h"

struct vector *vector_init(size_t n)
{
    struct vector *new = malloc(sizeof(struct vector));
    new->size = 0;
    new->capacity = n;
    new->data = malloc(sizeof(int) * n);
    return new;
}
