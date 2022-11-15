void my_strlowcase(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += 32;
        }
        str += 1;
    }
}
