#include <stdlib.h>

#include "vector.h"

void vector_destroy(struct vector *v)
{
    if (v)
    {
        if (v->data)
        {
            free(v->data);
        }
        free(v);
    }
}
