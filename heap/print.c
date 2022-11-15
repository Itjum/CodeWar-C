#include <stddef.h>
#include <stdio.h>

#include "heap.h"

int size_val(int value)
{
    int n = value;
    int len = 0;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

char *my_itoa(int value, char *s)
{
    int i = 0;
    int rem;
    int len = 0;
    if (value < 0)
    {
        value = -value;
        len = size_val(value);
        for (; i < len; i++)
        {
            rem = value % 10;
            value = value / 10;
            s[len - i] = rem + '0';
        }
        s[0] = '-';
        s[len + 1] = '\0';
    }
    else
    {
        if (value == 0)
        {
            len = 1;
        }
        else
        {
            len = size_val(value);
        }

        for (; i < len; i++)
        {
            rem = value % 10;
            value = value / 10;
            s[len - (i + 1)] = rem + '0';
        }
        s[len] = '\0';
    }
    return s;
}

void print_heap2(int *array, size_t i, size_t size)
{
    if (i >= size)
        return;
    char s[1000];
    char *c = my_itoa(array[i], s);
    while (*c != '\0')
    {
        putchar(*c);
        c++;
    }
    if (i >= size - 1)
        return;
    if (2 * i + 1 < size)
    {
        putchar(' ');
        print_heap2(array, 2 * i + 1, size);
    }
    if (2 * i + 2 < size)
    {
        putchar(' ');
        print_heap2(array, 2 * i + 2, size);
    }
}

void print_heap(const struct heap *heap)
{
    size_t i = 0;
    if (!heap || heap->size == 0)
    {
        return;
    }
    size_t size = heap->size;
    print_heap2(heap->array, i, size);
    putchar('\n');
}
