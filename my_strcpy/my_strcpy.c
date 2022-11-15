#include <stddef.h>

char *my_strcpy(char *dest, const char *source)
{
    if (dest == NULL)
        return NULL;
    char *res = dest;
    while (*source != '\0')
    {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
    return res;
}
