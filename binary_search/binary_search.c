#include <stddef.h>

int binary_search(const int vect[], size_t size, int elt)
{
    if (vect == NULL)
        return -1;
    if (size == 0)
        return -1;
    if (size == 1)
    {
        if (vect[0] == elt)
            return 0;
        else
            return -1;
    }
    unsigned int left = 0;
    unsigned int right = size - 1;
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (vect[mid] == elt)
        {
            return mid;
        }
        if (vect[mid] < elt)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
