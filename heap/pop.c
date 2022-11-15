#include <assert.h>

#include "heap.h"

void swap(int *array, size_t index1, size_t index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void swap_recursive2(int *array, size_t index, size_t size)
{
    if (index * 2 + 2 < size)
    {
        size_t a = index * 2 + 2;
        size_t b = index * 2 + 1;
        if (array[a] > array[b])
        {
            if (array[index] < array[a])
            {
                swap(array, index, (a));
                swap_recursive2(array, a, size);
            }
        }
        else
        {
            if (array[index] < array[b])
            {
                swap(array, index, (b));
                swap_recursive2(array, b, size);
            }
        }
    }
    else if (index * 2 + 1 < size)
    {
        size_t a = index * 2 + 1;
        if (array[index] < array[a])
        {
            swap(array, index, a);
        }
    }
}

int pop(struct heap *heap)
{
    if (!heap)
    {
        return -1;
    }
    assert(heap->size >= 1 && "The pop function needs at least one element");
    int res = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size -= 1;
    size_t i = 0;
    swap_recursive2(heap->array, i, heap->size);
    return res;
}
