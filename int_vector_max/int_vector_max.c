#include "int_vector_max.h"

int int_vector_max(const struct int_vector vec)
{
    int max = vec.data[0];
    size_t size = vec.size;
    for (size_t i = 0; i < size; i++)
    {
        if (vec.data[i] > max)
        {
            max = vec.data[i];
        }
    }
    return max;
}
