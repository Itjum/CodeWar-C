#include "my_strtok_r.h"

#include <stddef.h>

size_t my_strcspn(const char *str, const char *foul)
{
    size_t i = 0;
    for (; str[i]; i++)
    {
        for (size_t j = 0; foul[j]; j++)
            if (str[i] == foul[j])
                return i;
    }
    return i;
}

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

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *res;
    if (!str)
        str = *saveptr;
    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    res = str + my_strcspn(str, delim);
    if (*res == '\0')
    {
        *saveptr = res;
        return str;
    }
    *res = '\0';
    *saveptr = res + 1;
    return str;
}
