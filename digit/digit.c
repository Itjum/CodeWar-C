#include <stddef.h>

unsigned int digit(int n, int k)
{
    unsigned int res = 0;
    if (n <= 0 || k <= 0)
    {
        return res;
    }
    for (int i = 1; i < k; i++)
    {
        n /= 10;
    }
    res = n % 10;
    return res;
}
