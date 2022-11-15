#include "string_replace.h"

int my_strlen(const char *s)
{
    int count = 0;
    if (s)
    {
        while (s[count])
        {
            count++;
        }
    }
    return count;
}

long long mem_calculate(char c, const char *str, const char *pattern)
{
    long long l = my_strlen(pattern);
    long long i = 0;
    long long count = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            count += l;
        }
        else
        {
            count++;
        }
        i++;
    }
    return count;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;
    char *res = malloc(mem_calculate(c, str, pattern) + 1);
    if (!res)
        return NULL;
    int t = 0;
    if (pattern != NULL)
    {
        while (pattern[t] != '\0')
            t++;
    }
    int i = 0;
    int end = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            int j = 0;
            while (j < t)
            {
                res[end] = pattern[j];
                j++;
                end++;
            }
            i++;
        }
        else
        {
            res[end] = str[i];
            end++;
            i++;
        }
    }
    res[end] = '\0';
    return res;
}
