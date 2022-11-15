#include <stddef.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n == v->capacity)
    {
        return v;
    }
    else if (n > v->capacity)
    {
        v->capacity = n;
        v->data = realloc(v->data, sizeof(int) * n);
        if (v->data == NULL)
            return NULL;
    }
    else if (n < v->size)
    {
        v->capacity = n;
        v->size = n;
        v->data = realloc(v->data, sizeof(int) * n);
        if (v->data == NULL)
            return NULL;
    }
    return v;
}
