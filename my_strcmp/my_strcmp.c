int my_strcmp(const char *s1, const char *s2)
{
    int value1 = 0;
    int value2 = 0;
    while (*s1)
    {
        value1 += *s1;
        s1++;
    }
    while (*s2)
    {
        value2 += *s2;
        s2++;
    }
    return (value1 - value2);
}
