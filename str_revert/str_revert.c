#include <stddef.h>

size_t my_strlen(char s[])
{
    size_t res = 0;
    while (*s)
    {
        res += 1;
        s += 1;
    }
    return res;
}

void str_revert(char str[])
{
    if (str != NULL)
    {
        size_t len = my_strlen(str);
        size_t low = 0;
        if (len != 0)
        {
            len -= 1;
            while (len > low)
            {
                char temp = str[len];
                str[len] = str[low];
                str[low] = temp;
                len--;
                low++;
            }
        }
    }
}
