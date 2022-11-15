#include <stddef.h>


int vmax(const int *const ptr, size_t size)
{
    int max1 = ptr[0];
    int max2 = ptr[1];
    if (max1 < max2)
    {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }
    for (size_t i = 1; i < size; i++)
    {
        if (ptr[i] > max1)
        {
            max2 = max1;
            max1 = ptr[i];
        }
    }
    return max2;
}
