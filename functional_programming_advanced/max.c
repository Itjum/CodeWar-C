#include "functional_programming_advanced.h"

int max(int *array, size_t len)
{
    if (len == 0)
        return 0;
    size_t i = 0;
    int max = array[0];
    while (i < len)
    {
        if (max < array[i])
            max = array[i];
        i++;
    }
    return max;
}
