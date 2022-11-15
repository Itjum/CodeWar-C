#include "list.h"

void list_print(struct list *l)
{
    if (l)
    {
        struct list *temp = l;
        while (temp->next)
        {
            int data = temp->data;
            printf("%d ", data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    printf("\n");
}
