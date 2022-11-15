#include <stddef.h>
#include <stdio.h>

#include "dlist.h"

size_t dlist_size(const struct dlist *list)
{
    if (list == NULL)
    {
        return 0;
    }
    return list->size;
}
