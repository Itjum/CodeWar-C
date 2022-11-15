#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int main(void)
{
    struct dlist *l = dlist_init();
    struct dlist *l2 = dlist_init();
    printf("%d\n", dlist_add_sort(l, 23));
    dlist_add_sort(l, 12);
    dlist_add_sort(l, 1);
    dlist_push_back(l2, 6);
    dlist_push_back(l2, 1);
    dlist_push_back(l2, 73);
    dlist_push_back(l2, 72);
    dlist_push_back(l2, 235);
    dlist_push_back(l2, 6);
    dlist_push_back(l, 1);
    dlist_push_back(l, 73);
    dlist_push_back(l, 72);
    dlist_push_back(l, 235);
    dlist_push_back(l, 6);
    dlist_push_back(l, 1);
    dlist_push_back(l, 73);
    dlist_push_back(l, 72);
    dlist_push_back(l, 235);
    dlist_push_back(l, 135);
    dlist_merge(l, l2); // lol
    dlist_sort(l);
    dlist_add_sort(l, 12);
    dlist_add_sort(l, 1200);
    printf("list: \n");
    dlist_print(l);
    printf("shifted list: \n");
    dlist_shift(l, 13);
    dlist_print(l);
    printf("after sorting dlist:\n");
    dlist_sort(l);
    dlist_print(l);
    printf("after add_sort: \n");
    dlist_add_sort(l, 12);
    dlist_print(l);
    unsigned int lev = dlist_levenshtein(l, l2);
    printf("levensthein distance = %d\n", lev);
    printf("after several removes: \n");
    dlist_remove_eq(l, 235);
    dlist_remove_eq(l, 235);
    dlist_remove_eq(l, 1);
    dlist_remove_eq(l, 73);
    dlist_remove_eq(l, 72);
    dlist_remove_eq(l, 135);
    dlist_remove_eq(l, 6);
    dlist_print(l);
    dlist_push_front(l, 666);
    printf("after sorting dlist2:\n");
    dlist_sort(l);
    dlist_print(l);
    struct dlist *new = dlist_copy(l);
    printf("test dlist copy:\n");
    dlist_print(new);
    printf("list1 after merge:\n");
    dlist_merge(l, new);
    dlist_print(l);
    printf("list2 after merge:\n");
    dlist_print(new);
    dlist_clear(l);
    dlist_clear(l2);
    dlist_clear(new);
    dlist_print(l);
    dlist_print(l2);
    dlist_print(new);
    free(l);
    free(l2);
    free(new);
    return 0;
}
