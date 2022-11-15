#include "my_strcasecmp.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    int value1 = 0;
    int value2 = 0;
    while (*s1)
    {
        if (*s1 >= 'A' && *s1 <= 'Z')
        {
            value1 = value1 + 32 + *s1;
        }
        else
        {
            value1 += *s1;
        }
        s1++;
    }
    while (*s2)
    {
        if (*s2 >= 'A' && *s2 <= 'Z')
        {
            value2 = value2 + 32 + *s2;
        }
        else
        {
            value2 += *s2;
        }
        s2++;
    }
    return (value1 - value2);
}
