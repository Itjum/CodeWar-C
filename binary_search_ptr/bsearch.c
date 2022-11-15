#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    int *left = begin;
    int *right = end;
    if (left == right)
        return begin;
    /*if ((right - left) <= 2)
    {
        if (*begin >= elt)
            return begin;
        return begin + 1;
    }*/
    int *mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (*mid == elt)
        {
            return mid;
        }
        if (*mid < elt)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
