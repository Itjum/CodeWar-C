#include <stdio.h>
#include <stdlib.h>

int count(int arr[], int n)
{
    int i = 2;
    int count = 0;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        i++;
    }
    return count;
}

void sieve(int n)
{
    if (n > 2)
    {
        int *arr = malloc(sizeof(int) * 100000000);
        for (int i = 2; i < n + 1; i++)
        {
            arr[i] = 1;
        }
        for (int i = 0; i * i <= n; i++)
        {
            if (arr[i] == 1)
            {
                for (int j = i * i; j < n; j = j + i)
                {
                    arr[j] = 0;
                }
            }
        }
        printf("%d\n", count(arr, n));
        free(arr);
    }
}
/*
int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;
    sieve(atoi(argv[1]));
    return 0;
}*/
