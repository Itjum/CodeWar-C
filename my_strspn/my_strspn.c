#include "my_strspn.h"

size_t my_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    const char *t = accept;
    while (*s)
    {
        for (t = accept; *t && *t != *s; t++)
            ;
        if (!*t)
            return i;
        s++;
        i++;
    }
    return i;
}
