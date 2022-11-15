#include <stddef.h>

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int advance_str(const char *str)
{
    int i = 0;
    if (str == NULL)
        return -1;
    while (*str == ' ' && *str != '-' && *str != '+')
    {
        if (!(is_digit(*str)) && *str != ' ')
            return -1;
        str++;
        i++;
    }
    return i;
}

int my_atoi(const char *str)
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
    while (*str)
    {
        if (!(is_digit(*str)))
        {
            return 0;
        }
        res = res * 10;
        res += *str - '0';
        str++;
    }
    return res * neg;
}
