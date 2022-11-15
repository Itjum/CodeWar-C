#include <stdio.h>

void print_arr(int *arr, int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            printf("%d\n", i);
        }
    }
}

void sieve(int n)
{
    if (n >= 2)
    {
        int arr[1000];
        for (int i = 2; i < n + 1; i++)
        {
            arr[i] = 1;
        }
        for (int i = 0; i * i <= n; i++)
        {
            if (arr[i] == 1)
            {
                for (int j = i * i; j <= n; j = j + i)
                {
                    arr[j] = 0;
                }
            }
        }
        print_arr(arr, n);
    }
}
