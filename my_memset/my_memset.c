#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *temp = s;
    while (n > 0)
    {
        *temp = c;
        temp++;
        n--;
    }
    return s;
}
