#include <stddef.h>
#include <stdio.h>

#include "vector.h"

void vector_print(const struct vector *v)
{
    if (v)
    {
        if (v->size == 1)
        {
            printf("%d", v->data[0]);
        }
        else if (v->size > 0)
        {
            printf("%d", v->data[0]);
            for (size_t i = 1; i < v->size; i++)
            {
                printf(",%d", v->data[i]);
            }
        }
    }
    printf("\n");
}
