#include "my_atoi_base.h"

int find_val(char c, const char *base)
{
    for (int i = 0; base[i] != '\0'; i++)
    {
        if (c == base[i])
        {
            return i;
        }
    }
    return -1;
}

int advance_str(const char *str)
{
    int i = 0;
    if (str == NULL)
        return -1;
    while (*str == ' ')
    {
        str++;
        if (*str == '\0')
            return -1;
        i++;
    }
    return i;
}

int calculate_base(const char *base)
{
    int res = 0;
    while (*base)
    {
        res++;
        base++;
    }
    return res;
}

int my_atoi_base(const char *str, const char *base)
{
    int res = 0;
    int i = advance_str(str);
    if (i == -1 || *(str + i) == '\0')
        return 0;
    str = str + i;
    if (*str == '+')
        str++;
    int neg = 1;
    if (*str == '-')
    {
        neg = -1;
        str++;
    }
    i = 0;
    int base2 = calculate_base(base);
    while (*(str + i) != '\0')
    {
        int temp = find_val(*(str + i), base);
        if (temp == -1)
            return 0;
        res = (res * base2) + temp;
        i++;
    }
    return res * neg;
}
