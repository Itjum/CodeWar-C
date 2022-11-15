void rot_x(char *s, int x)
{
    if (!s)
        return;
    if (x < 0)
    {
        while (x < 0)
        {
            x = x + 26;
        }
    }
    if (x >= 26)
    {
        while (x >= 26)
        {
            x -= 26;
        }
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (s[i] - 'A' + x) % 26 + 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i] - 'a' + x) % 26 + 'a';
        }
    }
}
