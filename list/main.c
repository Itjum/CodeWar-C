#include "list.h"

int is_even(int data)
{
    if (data % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    struct list *l = NULL;
    l = list_reverse_sorted_add(l, 0);
    l = list_add(l, 1);
    l = list_add(l, 3);
    l = list_add(l, 6);
    l = list_add(l, 9);
    l = list_add(l, 12);
    l = list_reverse_sorted_add(l, -5);
    l = list_reverse_sorted_add(l, 8);
    l = list_reverse_sorted_add(l, 20);
    list_print(l);
    struct list *f = list_find(l, 9);
    struct list *f2 = list_find(l, 651651);
    printf("%d \n", f->data);
    if (f2 == NULL)
    {
        printf("find works\n");
    }
    printf("after list remove if:\n");
    l = list_remove_if(l, is_even);
    list_print(l);
    struct list *temp = l->next;
    while (temp)
    {
        free(l);
        l = temp;
        temp = temp->next;
    }
    free(l);
}
