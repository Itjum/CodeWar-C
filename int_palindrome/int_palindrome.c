static int reverse_n(int n)
{
    int reverse = 0;
    while (n != 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}

int int_palindrome(int n)
{
    if (n < 0)
    {
        return 0;
    }
    int reverse = reverse_n(n);
    if (reverse == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
