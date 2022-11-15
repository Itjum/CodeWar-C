#include <stddef.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;
    size_t i = v->size;
    if (i == v->capacity)
    {
        v = vector_resize(v, v->capacity * 2);
        if (v == NULL)
            return NULL;
    }
    v->data[i] = elt;
    v->size += 1;
    return v;
}
