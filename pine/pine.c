#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }
    else
    {
        unsigned int t = 0;
        unsigned int lim = 1;
        for (unsigned int i = 0; i < n; i++)
        {
            t += 1;
            for (unsigned int j = 0; j < n - t; j++)
            {
                putchar(' ');
            }
            for (unsigned int s = 0; s < lim; s++)
            {
                putchar('*');
            }
            putchar('\n');
            lim += 2;
        }
        for (unsigned int x = 0; x < n / 2; x++)
        {
            for (unsigned int y = 0; y < n - 1; y++)
            {
                putchar(' ');
            }
            putchar('*');
            putchar('\n');
        }
        return 0;
    }
}
