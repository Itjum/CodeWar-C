#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t x = 0;
    while (x < vec.size - 1)
    {
        printf("%d ", vec.data[x]);
        x++;
    }
    printf("%d\n", vec.data[x]);
}
