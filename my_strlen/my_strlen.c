#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res += 1;
        s++;
    }
    return res;
}
