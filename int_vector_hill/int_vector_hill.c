#include "int_vector_hill.h"

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
        return -1;
    if (vec.size == 1)
        return 0;
    int max = vec.data[0];
    if (max < 0)
        return -1;
    int stop = 0;
    size_t size = vec.size;
    size_t i = 1;
    int res = 0;
    for (; i < size && stop == 0; i++)
    {
        if (vec.data[i] < 0)
            return -1;
        if (vec.data[i] > max)
        {
            max = vec.data[i];
            res = i;
        }
        else if (vec.data[i] < max)
        {
            stop = 1;
        }
    }
    i--;
    for (size_t j = i; j < size - 1; j++)
    {
        if (vec.data[j] < 0 || vec.data[j + 1] < 0
            || vec.data[j] < vec.data[j + 1])
            return -1;
    }
    return res;
}
