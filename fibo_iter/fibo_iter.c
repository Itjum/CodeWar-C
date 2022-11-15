#include <stddef.h>

unsigned long fibo_iter(unsigned long n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    unsigned long a = 1;
    unsigned long b = 1;
    unsigned long c = 1;
    for (unsigned long i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
