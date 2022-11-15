#include "heap_sort.h"

void heapify(int *array, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        i++;
    }
}

void heap_sort(int *array, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        i++;
    }
}
