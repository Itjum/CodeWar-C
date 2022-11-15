#include <stdlib.h>

#include "heap.h"

void swap_heap(int *array, size_t index1, size_t index2)
{
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void swap_recursive(int *array, size_t size)
{
    if (size == 0)
        return;
    if (array[size] > array[(size - 1) / 2])
    {
        swap_heap(array, size, (size - 1) / 2);
        swap_recursive(array, (size - 1) / 2);
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        int *temp = realloc(heap->array, sizeof(int) * heap->capacity * 2);
        if (!(temp == NULL))
        {
            heap->capacity *= 2;
            heap->array = temp;
            heap->array[heap->size] = val;
            size_t size = heap->size;
            heap->size += 1;
            swap_recursive(heap->array, size);
        }
        else
            return;
    }
    else if (heap->size == 0)
    {
        heap->array[0] = val;
        heap->size = 1;
    }
    else
    {
        heap->array[heap->size] = val;
        size_t size = heap->size;
        heap->size += 1;
        swap_recursive(heap->array, size);
    }
}
