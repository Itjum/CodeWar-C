#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    if (roll == 0)
        return value;
    unsigned int tmp = value;
    unsigned int tmp2;
    for (roll %= 8; roll > 0; roll--)
    {
        tmp2 = (tmp >> 7) & 1;
        tmp = (tmp << 1) | tmp2;
    }
    value = tmp;
    return value;
}
