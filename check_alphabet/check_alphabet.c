#include "check_alphabet.h"

#include <stddef.h>

int my_strcmp(const char *s1, const char *s2)
{
    int value1 = 0;
    int value2 = 0;
    while (*s1)
    {
        value1 += *s1;
        s1++;
    }
    while (*s2)
    {
        value2 += *s2;
        s2++;
    }
    return (value1 - value2);
}

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

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
        return 1;
    if (*alphabet == '\0')
        return 1;
    int verif = 1;
    int verif2 = 0;
    const char *temp = str;
    if (my_strlen(str) < my_strlen(alphabet))
    {
        return 0;
    }
    if (my_strcmp("", alphabet) == 0)
    {
        return 1;
    }
    if (my_strcmp(str, "") == 0)
        return 0;
    while (*alphabet && verif == 1)
    {
        verif2 = 0;
        while (*str && verif2 == 0)
        {
            if (*alphabet == *str)
            {
                verif2 = 1;
            }
            str += 1;
        }
        verif = (verif2 == 0) ? 0 : 1;
        str = temp;
        alphabet += 1;
    }
    return verif;
}
