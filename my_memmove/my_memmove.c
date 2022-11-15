#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    char *temp = dest;
    const char *s = src;
    if (dest < src)
    {
        while (i < n)
        {
            *temp = *s;
            temp++;
            s++;
            i++;
        }
        return dest;
    }
    else
    {
        char *lasts = (char *)(s + (n - 1));
        char *lastd = temp + (n - 1);
        while (n--)
            *lastd-- = *lasts--;
        return dest;
    }
}
