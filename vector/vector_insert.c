#include <stddef.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v)
    {
        if (i == v->size)
        {
            return vector_append(v, elt);
        }
        else if (i < v->size)
        {
            if (v->size == v->capacity)
            {
                v->capacity *= 2;
                v->data = realloc(v->data, v->capacity * 2);
                if (!v->data)
                {
                    return NULL;
                }
            }
            v->size++;
            size_t j = v->size - 1;
            while (j > i)
            {
                v->data[j] = v->data[j - 1];
                j--;
            }
            v->data[i] = elt;
            return v;
        }
    }
    return NULL;
}
