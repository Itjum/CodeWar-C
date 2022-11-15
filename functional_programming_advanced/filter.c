#include <stdio.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    *out_array = malloc(sizeof(int) * len);
    size_t i = 0;
    size_t j = 0;
    size_t res = 0;
    while (i < len)
    {
        if (func(array[i]) == true)
        {
            out_array[0][j] = array[i];
            j++;
            res++;
        }
        i++;
    }
    *out_array = realloc(*out_array, sizeof(int) * j);
    return res;
}
