#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int max2 = vec.data[1];
    if (max < max2)
    {
        int temp = max;
        max = max2;
        max2 = temp;
    }
    for (size_t i = 2; i < vec.size; i++)
    {
        if (max < vec.data[i])
        {
            max2 = max;
            max = vec.data[i];
        }
        else if (max2 < vec.data[i])
        {
            max2 = vec.data[i];
        }
    }
    return max2;
}
