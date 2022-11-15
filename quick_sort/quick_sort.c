#include <stddef.h>

int partition(int arr[], int low, int high)
{
    int p = arr[high];
    int i = (low - 1);
    int j = low;
    while (j < high)
    {
        if (arr[j] <= p)
        {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        j++;
    }
    i += 1;
    int tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    return i;
}

static void quicksort2(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quicksort2(array, low, pi - 1);
        quicksort2(array, pi + 1, high);
    }
}

void quicksort(int *tab, int len)
{
    if (tab != NULL)
    {
        if (len > 0)
        {
            int low = 0;
            int high = len - 1;
            quicksort2(tab, low, high);
        }
    }
}
