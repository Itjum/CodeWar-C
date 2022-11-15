#include <stdio.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned index = start;
    for (unsigned int i = start; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
    {
        return;
    }
    unsigned int i = 0;
    int min_i;
    for (i = 0; i < size - 1; i++)
    {
        min_i = array_min(arr, i + 1, size);
        if (arr[min_i] < arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = temp;
        }
    }
}
