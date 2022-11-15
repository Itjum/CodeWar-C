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
