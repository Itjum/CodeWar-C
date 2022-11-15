#include <stddef.h>

int foldr2(int *array, size_t len, int (*func)(int, int), int x)
{
    if (len == 0)
        return x;
    return func(*array, foldr2(array + 1, len - 1, func, x));
}

int foldr(int *array, size_t len, int (*func)(int, int))
{
    return foldr2(array, len, func, 0);
}
