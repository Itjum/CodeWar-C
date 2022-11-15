#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main(void)
{
    struct hash_map *t1 = hash_map_init(24);
    // values
    const char *k1 = "Ville";
    char *value1 = "Toulouse";
    const char *k2 = "Pays";
    char *value2 = "FRANCE";
    const char *k3 = "Continent";
    char *value3 = "Europe";
    const char *k4 = "Planete";
    char *value4 = "Terre";
    bool *updated = NULL;
    // test launch
    bool v1 = hash_map_insert(t1, k1, value1, updated);
    bool v2 = hash_map_insert(t1, k2, value2, updated);
    bool v3 = hash_map_insert(t1, k3, value3, updated);
    bool v4 = hash_map_insert(t1, k4, value4, updated);
    printf("%d\n", v1);
    printf("%d\n", v2);
    printf("%d\n", v3);
    printf("%d\n", v4);
    printf("my hash map:\n");
    hash_map_dump(t1);
    printf("get hash map:\n");
    const char *gethash = hash_map_get(t1, k3);
    printf("%s\n", gethash);
    gethash = hash_map_get(t1, k4);
    printf("%s\n", gethash);
    gethash = hash_map_get(t1, k1);
    printf("%s\n", gethash);
    gethash = hash_map_get(t1, k2);
    printf("%s\n", gethash);
    const char *kbad = "truc";
    gethash = hash_map_get(t1, kbad);
    bool vv1 = hash_map_remove(t1, k2);
    printf("remove: %d\n", vv1);
    hash_map_free(t1);
    free(updated);
}
