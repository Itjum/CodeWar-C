#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    FILE *file = fopen(argv[1], "r");
    if (!file)
        return 1;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file)) != -1)
    {
        char *useless = NULL;
        char *n = NULL;
        int num = 0;
        int verif = 0;
        int max;
        char *s = line;
        while (1)
        {
            n = strtok_r(s, ",", &useless);
            if (!n)
                break;
            else
                num = atoi(n);
            if (verif == 0)
            {
                verif = 1;
                max = num;
            }
            if (num > max)
                max = num;
            s = NULL;
        }
        printf("%d\n", max);
    }
    free(line);
    fclose(file);
    return 0;
}
