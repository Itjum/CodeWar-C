int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int tmp = i;
        while ((i * i) < n)
        {
            tmp = i;
            i++;
        }
        if (i * i == n)
            return i;
        else
            return tmp;
    }
}
