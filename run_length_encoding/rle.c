#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int size_val(int value)
{
    int n = value;
    int len = 0;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

char *my_itoa(int value, char *s)
{
    int i = 0;
    int rem;
    int len = 0;
    if (value < 0)
    {
        value = -value;
        len = size_val(value);
        for (; i < len; i++)
        {
            rem = value % 10;
            value = value / 10;
            s[len - i] = rem + '0';
        }
        s[0] = '-';
        s[len + 1] = '\0';
    }
    else
    {
        if (value == 0)
        {
            len = 1;
        }
        else
        {
            len = size_val(value);
        }

        for (; i < len; i++)
        {
            rem = value % 10;
            value = value / 10;
            s[len - (i + 1)] = rem + '0';
        }
        s[len] = '\0';
    }
    return s;
}

char *rle_encode(const char *s)
{
    if (!s)
        return NULL;
    char *res = malloc(sizeof(char) * 100000);
    res[0] = '\0';
    char c = *s;
    char *c2 = malloc(sizeof(char) * 2);
    char *t = malloc(sizeof(2));
    t[1] = '\0';
    c2[1] = '\0';
    int count = 0;
    int i = 0;
    while (*s)
    {
        c2[0] = c;
        if (*s != c || *(s + 1) == '\0')
        {
            if (*(s + 1) == '\0' && *s == c)
                count++;
            t = my_itoa(count, t);
            i += 2;
            strcat(res, t);
            strcat(res, c2);
            count = 1;
            c = *s;
        }
        else if (count == 9)
        {
            t = my_itoa(count, t);
            i += 2;
            strcat(res, t);
            strcat(res, c2);
            count = 1;
        }
        else
            count++;
        s++;
    }
    if (*(s - 1) != c2[0])
    {
        res[i] = '1';
        res[i + 1] = *(s - 1);
        i += 2;
    }
    free(t);
    free(c2);
    res[i] = '%';
    res[i + 1] = '\0';
    return res;
}

char *rle_decode(const char *s)
{
    char *res = malloc(sizeof(char) * 100000);
    res[0] = '\0';
    char *t = malloc(sizeof(2));
    t[1] = '\0';
    int count = 0;
    int i = 0;
    int x = 0;
    while (*s)
    {
        if (x % 2 == 0)
        {
            t[0] = *s;
            count = atoi(t);
        }
        else
        {
            char c = *s;
            for (int j = 0; j < count; j++)
            {
                res[i] = c;
                i++;
            }
        }
        x++;
        s++;
    }
    free(t);
    res[i] = '%';
    res[i + 1] = '\0';
    return res;
}
