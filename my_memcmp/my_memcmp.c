#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    size_t i = 0;
    int value1 = 0;
    int value2 = 0;
    const char *t1 = s1;
    const char *t2 = s2;
    while (i < num)
    {
        value1 += *t1;
        t1++;
        i++;
    }
    i = 0;
    while (i < num)
    {
        value2 += *t2;
        t2++;
        i++;
    }
    return (value1 - value2);
}
