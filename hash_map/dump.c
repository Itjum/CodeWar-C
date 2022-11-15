#include <stdio.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash)
{
    if (hash)
    {
        if (hash->data)
        {
            for (size_t i = 0; i < hash->size; i++)
            {
                struct pair_list *temp = hash->data[i];
                if (temp)
                {
                    if (temp->next)
                    {
                        struct pair_list *prev = temp;
                        struct pair_list *temp2 = temp->next;
                        while (temp2)
                        {
                            printf("%s: %s, ", prev->key, prev->value);
                            prev = temp2;
                            temp2 = temp2->next;
                        }
                        printf("%s: %s\n", prev->key, prev->value);
                    }
                    else
                    {
                        printf("%s: %s\n", temp->key, temp->value);
                    }
                }
            }
        }
    }
}