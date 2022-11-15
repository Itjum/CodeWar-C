#include <stdlib.h>

#include "vector.h"

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
    {
        return NULL;
    }
    size_t p = v->size - 1;
    if (i == p)
    {
        v->data[i] = 0;
    }
    else
    {
        while (i < p)
        {
            v->data[i] = v->data[i + 1];
            i++;
        }
    }
    v->size -= 1;
    if (v->capacity > 2 * v->size)
    {
        int cap = v->capacity / 2;
        v->capacity = cap;
        v->data = realloc(v->data, sizeof(int) * cap);
        if (v->data == NULL)
            return NULL;
    }
    return v;
}
