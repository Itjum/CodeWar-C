#include "variant.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    default:
        printf("%d\n", e->value.int_v);
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    bool verif = false;
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->type == right->type)
    {
        switch (left->type)
        {
        case TYPE_INT:
            verif = (left->value.int_v == right->value.int_v) ? true : false;
            break;
        case TYPE_FLOAT:
            verif =
                (left->value.float_v == right->value.float_v) ? true : false;
            break;
        case TYPE_CHAR:
            verif = (left->value.char_v == right->value.char_v) ? true : false;
            break;
        case TYPE_STRING:
            verif = (strcmp(left->value.str_v, right->value.str_v) == 0)
                ? true
                : false;
            break;
        default:
            return verif;
        }
    }
    return verif;
}

int find_element(const struct variant *array, size_t len, union type_any value,
                 enum type type)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        if (array[i].type == type)
        {
            if (array[i].value.int_v == value.int_v)
            {
                return i;
            }
        }
    }
    return -1;
}

int find_element1(const struct variant *array, size_t len, union type_any value,
                  enum type type)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        if (array[i].type == type)
        {
            if (array[i].value.float_v == value.float_v)
            {
                return i;
            }
        }
    }
    return -1;
}

int find_element2(const struct variant *array, size_t len, union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].value.char_v == value.char_v)
        {
            return i;
        }
    }
    return -1;
}
int find_element3(const struct variant *array, size_t len, union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        if (strcmp(array[i].value.str_v, value.str_v) == 0)
        {
            return i;
        }
    }
    return -1;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    if (!array || len == 0)
        return -1;
    switch (type)
    {
    case TYPE_INT:
        return find_element(array, len, value, type);
    case TYPE_FLOAT:
        return find_element1(array, len, value, type);
    case TYPE_CHAR:
        return find_element2(array, len, value);
    case TYPE_STRING:
        return find_element3(array, len, value);
    default:
        return -1;
    }
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_INT)
        {
            res += array[i].value.int_v;
        }
        if (array[i].type == TYPE_FLOAT)
        {
            res += array[i].value.float_v;
        }
    }
    return res;
}
