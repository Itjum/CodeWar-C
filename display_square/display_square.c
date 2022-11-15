#include <stdio.h>

void display_square(int width)
{
    if (width > 1)
    {
        if (width % 2 == 0)
        {
            width += 1;
        }
        for (int i = 0; i < width; i++)
        {
            putchar('*');
        }
        putchar('\n');
        for (int j = 0; j < ((width + 1) / 2) - 2; j++)
        {
            putchar('*');
            for (int p = 1; p < width - 1; p++)
            {
                putchar(' ');
            }
            putchar('*');
            putchar('\n');
        }
        for (int i = 0; i < width; i++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    display_square(1);
}
