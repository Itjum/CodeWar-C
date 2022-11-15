#include "dlist.h"

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list1->size == 0 || list2->size == 0)
        return;
    dlist_concat(list1, list2);
    dlist_sort(list1);
}
