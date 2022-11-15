#include <stddef.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v)
    {
        v->size = 0;
        v->capacity = n;
        free(v->data);
        v->data = malloc(sizeof(int) * n);
        if (v->data)
        {
            return v;
        }
    }
    return NULL;
}
