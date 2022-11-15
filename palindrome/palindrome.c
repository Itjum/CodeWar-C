#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s)
    {
        res += 1;
        s += 1;
    }
    return res;
}

int check(char c1)
{
    int check;
    if ((c1 <= 'Z' && c1 >= 'A') || (c1 <= 'z' && c1 >= 'a'))
    {
        check = 1;
    }
    else if (c1 <= '9' && c1 >= '0')
    {
        check = 2;
    }
    else
    {
        check = 0;
    }
    return check;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    if (s[0] == '\0')
        return 1;
    size_t len = my_strlen(s) - 1;
    size_t low = 0;
    while (len > low)
    {
        if (check(s[low]) == 0 && check(s[len]) == 0)
        {
            low++;
            len--;
        }
        else if (check(s[low]) == 0)
        {
            low++;
        }
        else if (check(s[len]) == 0)
        {
            len--;
        }
        else
        {
            if (s[len] != s[low])
            {
                return 0;
            }
            len--;
            low++;
        }
    }
    return 1;
}
