#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int main(void)
{
    struct dlist *l = dlist_init();
    struct dlist *l3 = dlist_init();
    dlist_push_back(l3, 9);
    dlist_push_front(l3, 3);
    dlist_push_front(l3, 2);
    dlist_push_front(l3, 1);
    dlist_push_back(l3, 9);
    dlist_push_front(l, 9);
    dlist_push_back(l, 3);
    dlist_push_back(l, 2);
    dlist_push_front(l, 1);
    dlist_push_front(l, 1);
    dlist_push_back(l, 1);
    dlist_push_back(l, 9);
    dlist_map_square(l);
    dlist_insert_at(l, 666, 2);
    dlist_insert_at(l, 666, 6);
    printf("found: %d\n", dlist_find(l, 666));
    printf("not found: %d\n", dlist_find(l, 777));
    printf("remove at: %d\n", dlist_remove_at(l, 3));
    struct dlist *new =
        dlist_split_at(l, 5); // comprendre pourquoi pour la valeur 5, 4, et 3
                              // ca me fait des erreurs differentes
    printf("half first list l:\n"); // valeur 3 et 4 corriges, manque plus que
                                    // la 5 memory leak
    dlist_print(l);
    printf("second half 'new' list:\n");
    dlist_print(new);
    printf("reverse list l: \n");
    dlist_reverse(l);
    dlist_print(l);
    printf("list 3: \n");
    dlist_print(l3);
    printf("concatenate list1 with list3:\n");
    dlist_concat(l, l3);
    dlist_print(l);
    printf("element at index 2: %d\n", dlist_get(l, 2));
    dlist_remove_at(l, 3);
    dlist_remove_at(l, 0);
    dlist_remove_at(l, 5);
    dlist_remove_at(l, 0);
    dlist_remove_at(l, 2);
    dlist_remove_at(l, 0);
    dlist_remove_at(l, 0);
    dlist_remove_at(l, 0);
    dlist_remove_at(l, 1);
    dlist_remove_at(l, 0);
    dlist_remove_at(new, 0);
    dlist_remove_at(new, 2);
    dlist_remove_at(new, 3);
    dlist_remove_at(new, 0);
    dlist_remove_at(new, 0);
    dlist_remove_at(new, 0);
    free(l);
    free(l3);
    free(new);
    return 0;
}
