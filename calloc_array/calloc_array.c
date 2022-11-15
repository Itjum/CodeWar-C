#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
    {
        return NULL;
    }
    int *res = malloc(sizeof(int) * size);
    if (!res)
    {
        return NULL;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = init;
        }
        return res;
    }
}
