unsigned long fibonacci(unsigned long n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
        return (fibonacci(n - 2) + fibonacci(n - 1));
}
