#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *temp = dest;
    const char *s = source;
    size_t i = 0;
    while (i < num)
    {
        *temp = *s;
        temp++;
        s++;
        i++;
    }
    return dest;
}
