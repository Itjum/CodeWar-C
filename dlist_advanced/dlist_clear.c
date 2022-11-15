#include <stdlib.h>

#include "dlist.h"

void dlist_clear(struct dlist *list)
{
    if (list == NULL || list->size == 0)
    {
        return;
    }
    while (list->size > 0)
    {
        dlist_remove_at(list, 0);
    }
}
