#include "my_itoa_base.h"

int base_convert(const char *base)
{
    int i = 0;
    while (base[i] != '\0')
    {
        i++;
    }
    return i;
}

static void reverse(char *s, int i)
{
    int len = i;
    i = 0;
    while (i < len / 2)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
        i++;
    }
}

int maj(const char *base)
{
    int check = 0;
    for (int i = 0; base[i] != '\0' && check == 0; i++)
    {
        if (base[i] >= 'a' && base[i] <= 'z')
        {
            check = 1;
        }
    }
    return check;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int i = 0;
    int isNegative = 0;
    int nbase = base_convert(base);
    int check = maj(base);
    if (n == 0)
    {
        s[i++] = '0';
        s[i] = '\0';
        return s;
    }
    if (n < 0 && nbase == 10)
    {
        isNegative = 1;
        n = -n;
    }
    while (n != 0)
    {
        int rem = n % nbase;
        if (check == 1)
        {
            s[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        }
        else
        {
            s[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
        }
        n = n / nbase;
    }
    if (isNegative == 1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
    return s;
}
