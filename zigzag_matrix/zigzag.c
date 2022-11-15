#include <stddef.h>
#include <stdlib.h>

int *zigzag(size_t n)
{
    if (n <= 0)
    {
        return NULL;
    }
    int *res = malloc(sizeof(int) * n * n);
    int m = 0;
    for (size_t i = 0; i < n * 2; i++)
    {
        for (size_t j = ((i < n) ? 0 : i - n + 1); j <= i && j < n; j++)
        {
            res[(i & 1) ? j * (n - 1) + i : (i - j) * n + j] = m++;
        }
    }
    return res;
}
