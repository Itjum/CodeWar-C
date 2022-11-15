#include <stdio.h>

#include "functional_programming_advanced.h"

bool even2(int x)
{
    if (x % 2 != 0)
        return false;
    return true;
}

void print_even(int *array, size_t len)
{
    size_t i = 0;
    while (i < len)
    {
        if (even2(array[i]) == 1)
        {
            printf("%d\n", array[i]);
        }
        i++;
    }
}
