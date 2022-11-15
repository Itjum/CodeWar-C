#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    int res = 0;
    if (len == 1)
    {
        return 0;
    }
    else
    {
        size_t i = 0;
        size_t j = i + 1;
        int max = tab[i];
        while (j < len && tab[j] >= tab[i])
        {
            if (max < tab[j])
            {
                max = tab[j];
                res = j;
            }
            i++;
            j++;
        }
        while (j < len)
        {
            if (tab[j] > tab[i])
            {
                return -1;
            }
            i++;
            j++;
        }
    }
    return res;
}
