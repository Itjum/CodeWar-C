#include "levenshtein.h"

size_t min(size_t a, size_t b, size_t c)
{
    if (a <= b && a <= c)
    {
        return a;
    }
    else if (b <= a && b <= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

size_t my_strlen(const char *s)
{
    size_t r = 0;
    while (*s != '\0')
    {
        r += 1;
        s++;
    }
    return r;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t s1len = my_strlen(s1);
    size_t s2len = my_strlen(s2);
    size_t matrix[s2len + 1][s1len + 1];
    matrix[0][0] = 0;
    for (size_t i = 1; i <= s2len; i++)
    {
        matrix[i][0] = matrix[i - 1][0] + 1;
    }
    for (size_t j = 1; j <= s1len; j++)
    {
        matrix[0][j] = matrix[0][j - 1] + 1;
    }
    for (size_t i = 1; i <= s2len; i++)
    {
        for (size_t j = 1; j <= s1len; j++)
        {
            size_t t1 = matrix[i - 1][j] + 1;
            size_t t2 = matrix[i][j - 1] + 1;
            size_t t3 =
                matrix[i - 1][j - 1] + ((s1[j - 1] == s2[i - 1]) ? 0 : 1);
            matrix[i][j] = min(t1, t2, t3);
        }
    }
    return (matrix[s2len][s1len]);
}
