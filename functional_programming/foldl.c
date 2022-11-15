#include <stddef.h>

int foldl2(int *array, size_t len, int (*func)(int, int), int x)
{
    if (len == 0)
        return x;
    return func(foldl2(array, len - 1, func, x), array[len - 1]);
}

int foldl(int *array, size_t len, int (*func)(int, int))
{
    return foldl2(array, len, func, 0);
}
