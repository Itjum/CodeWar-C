#include "dlist.h"

unsigned int min(unsigned int a, unsigned int b, unsigned int c)
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

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    size_t s1len = dlist_size(list1);
    size_t s2len = dlist_size(list2);
    unsigned int matrix[s2len + 1][s1len + 1];
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
            unsigned int t1 = matrix[i - 1][j] + 1;
            unsigned int t2 = matrix[i][j - 1] + 1;
            unsigned int t3 = matrix[i - 1][j - 1]
                + ((dlist_get(list1, j - 1) == dlist_get(list2, i - 1)) ? 0
                                                                        : 1);
            matrix[i][j] = min(t1, t2, t3);
        }
    }
    return (matrix[s2len][s1len]);
}
