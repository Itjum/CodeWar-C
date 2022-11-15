#include <stdio.h>

void hanoi_rec(unsigned n, char a, char b, char c)
{
    if (n != 0)
    {
        hanoi_rec(n - 1, a, c, b);
        putchar(a);
        putchar('-');
        putchar('>');
        putchar(b);
        putchar('\n');
        hanoi_rec(n - 1, c, b, a);
    }
}

void hanoi(unsigned n)
{
    char a = '1';
    char b = '3';
    char c = '2';
    hanoi_rec(n, a, b, c);
}
