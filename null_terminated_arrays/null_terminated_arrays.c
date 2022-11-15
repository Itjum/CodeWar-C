#include "null_terminated_arrays.h"

#include <stddef.h>

int size_array(const char **array)
{
    int res = 0;
    if (!array)
    {
        return res;
    }
    while (*array != NULL)
    {
        res++;
        array++;
    }
    return res;
}

int size_matrix(const char ***array)
{
    int r = 0;
    if (!array)
    {
        return r;
    }
    while (*array != NULL)
    {
        r++;
        array++;
    }
    return r;
}

void reverse_array(const char **array)
{
    int size = size_array(array) - 1;
    if (size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        const char *temp = array[i];
        array[i] = array[size];
        array[size] = temp;
        size--;
    }
}

void reverse_matrix(const char ***matrix)
{
    int size = size_matrix(matrix) - 1;
    if (size < 0)
    {
        return;
    }
    if (size == 0)
    {
        reverse_array(matrix[0]);
        return;
    }
    for (int j = 0; j <= size; j++)
    {
        reverse_array(matrix[j]);
    }
    for (int i = 0; i < size; i++)
    {
        const char **temp = matrix[i];
        matrix[i] = matrix[size];
        matrix[size] = temp;
        size--;
    }
}
