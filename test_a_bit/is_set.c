#include <stddef.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    if (value & (1 << (n - 1)))
        return 1;
    return 0;
}
/*
int main(void)
{
    printf("%d\n", is_set(24, 4));
    printf("%d\n", is_set(24, 3));
    return 0;
}*/
