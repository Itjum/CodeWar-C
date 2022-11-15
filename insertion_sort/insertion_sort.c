#include <stdlib.h>

typedef int (*f_cmp)(const void *, const void *);

int get_size(void **array)
{
    void **temp = array;
    int count = 0;
    while (temp != NULL)
    {
        temp++;
        count++;
    }
    return count;
}

void insertion_sort(void **array, f_cmp comp)
{
    void *temp;
    int i = 1;
    int size = get_size(array);
    while (i < size)
    {
        int j;
        if (comp(array[i], array[i - 1]) == -1)
        {
            temp = array[i];
            j = i - 1;
            while (j >= 0 && comp(array[j], temp) == 1)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = temp;
        }
        i++;
    }
}
