#include "hash_map.h"

#include <stdio.h>
#include <stdlib.h>

int my_strcmp(const char *s1, const char *s2)
{
    int value1 = 0;
    int value2 = 0;
    while (*s1)
    {
        value1 += *s1;
        s1++;
    }
    while (*s2)
    {
        value2 += *s2;
        s2++;
    }
    return (value1 - value2);
}

struct hash_map *hash_map_init(size_t size)
{
    if (size == 0)
        return NULL;
    struct hash_map *new = malloc(sizeof(struct hash_map));
    if (!new)
        return NULL;
    new->size = size;
    new->data = calloc(size, sizeof(struct pair_list));
    if (!new->data)
        return NULL;
    for (size_t i = 0; i < size; i++)
    {
        new->data[i] = NULL;
    }

    return new;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!key || !value || !hash_map)
    {
        return false;
    }
    size_t resHash = hash(key);
    size_t index = resHash % hash_map->size;
    if (index == hash_map->size)
        return false;
    if (updated)
        *updated = false;
    if (hash_map->data[index] == NULL)
    {
        hash_map->data[index] = malloc(sizeof(struct pair_list));
        if (!hash_map->data[index])
            return false;
        hash_map->data[index]->key = key;
        hash_map->data[index]->value = value;
        hash_map->data[index]->next = NULL;
    }
    else
    {
        if (my_strcmp(hash_map->data[index]->key, key) == 0)
        {
            hash_map->data[index]->value = value;
            if (updated)
                *updated = true;
        }
        else
        {
            struct pair_list *check = hash_map->data[index];
            int v = 0;
            while (check && v == 0)
            {
                if (my_strcmp(check->key, key) == 0)
                {
                    check->value = value;
                    v = 1;
                    if (updated)
                        *updated = true;
                }
                else
                {
                    check = check->next;
                }
            }
            if (v == 0)
            {
                struct pair_list *temp = hash_map->data[index];
                struct pair_list *new = malloc(sizeof(struct pair_list));
                if (!new)
                    return false;
                new->next = temp;
                new->key = key;
                new->value = value;
                hash_map->data[index] = new;
            }
        }
    }
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map)
    {
        if (hash_map->data)
        {
            for (size_t i = 0; i < hash_map->size; i++)
            {
                struct pair_list *temp = hash_map->data[i];
                if (temp)
                {
                    if (temp->next)
                    {
                        struct pair_list *prev = temp;
                        struct pair_list *temp2 = temp->next;
                        while (temp2)
                        {
                            free(prev);
                            prev = temp2;
                            temp2 = temp2->next;
                        }
                        free(prev);
                    }
                    else
                    {
                        free(temp);
                    }
                }
            }
            free(hash_map->data);
        }
        free(hash_map);
    }
}

size_t hash2(const char *key)
{
    size_t i = 0;
    size_t hash = 0;

    for (i = 0; key[i] != '\0'; ++i)
        hash += key[i];
    hash += i;

    return hash;
}

const char *hash_map_get(const struct hash_map *hash, const char *key)
{
    const char *res = NULL;
    if (hash)
    {
        if (hash->data)
        {
            size_t resHash = hash2(key);
            size_t index = resHash % hash->size;
            struct pair_list *temp = hash->data[index];
            if (temp)
            {
                if (my_strcmp(temp->key, key) == 0)
                    res = temp->value;
                else
                {
                    if (temp->next)
                    {
                        struct pair_list *prev = temp;
                        struct pair_list *temp2 = temp->next;
                        int verif = 0;
                        while (temp2 && verif == 0)
                        {
                            if (my_strcmp(prev->key, key) == 0)
                            {
                                res = prev->value;
                                verif = 1;
                            }
                            prev = temp2;
                            temp2 = temp2->next;
                        }
                        if (verif == 0)
                        {
                            if (my_strcmp(prev->key, key) == 0)
                                res = prev->value;
                        }
                    }
                }
            }
        }
    }
    return res;
}

bool hash_map_remove(struct hash_map *hash, const char *key)
{
    if (hash)
    {
        if (hash->data && hash->size > 0)
        {
            size_t resHash = hash2(key);
            size_t index = resHash % hash->size;
            struct pair_list *temp = hash->data[index];
            if (temp)
            {
                if (my_strcmp(temp->key, key) == 0)
                {
                    if (temp->next)
                    {
                        struct pair_list *prev = temp;
                        struct pair_list *temp2 = temp->next;
                        free(prev);
                        hash->data[index] = temp2;
                        return true;
                    }
                    else
                    {
                        free(temp);
                        hash->data[index] = NULL;
                        return true;
                    }
                }
                else
                {
                    if (temp->next)
                    {
                        struct pair_list *prev = temp;
                        struct pair_list *temp2 = temp->next;
                        while (temp2)
                        {
                            if (my_strcmp(temp2->key, key) == 0)
                            {
                                prev->next = temp2->next;
                                free(temp2);
                                temp2 = NULL;
                                return true;
                            }
                            prev = temp2;
                            temp2 = temp2->next;
                        }
                    }
                }
            }
        }
    }
    return false;
}
