#include "list.h"

struct list *list_add(struct list *l, int e)
{
    if (!l)
    {
        struct list *new = malloc(sizeof(struct list));
        if (!new)
            return l;
        new->data = e;
        new->next = NULL;
        return new;
    }
    else
    {
        struct list *new = malloc(sizeof(struct list));
        if (!new)
            return l;
        new->data = e;
        new->next = l;
        return new;
    }
}

struct list *list_find(struct list *l, int e)
{
    if (!l)
    {
        return NULL;
    }
    else
    {
        struct list *temp = l;
        while (temp && temp->data != e)
        {
            temp = temp->next;
        }
        return temp;
    }
}

struct list *list_remove(struct list *l, int e)
{
    if (!l)
    {
        return NULL;
    }
    else
    {
        if (!l->next)
        {
            if (l->data == e)
            {
                free(l);
                return NULL;
            }
            return l;
        }
        if (l->data == e)
        {
            struct list *t = l->next;
            free(l);
            return t;
        }
        struct list *temp = l;
        struct list *temp2 = temp;
        while (temp)
        {
            if (temp->data == e)
            {
                temp2->next = temp->next;
                free(temp);
                return l;
            }
            temp2 = temp;
            temp = temp->next;
        }
        return l;
    }
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (!l)
    {
        return list_add(l, e);
    }
    struct list *temp = l;
    if (e >= l->data)
    {
        l = list_add(l, e);
    }
    else if (!l->next)
    {
        struct list *t = NULL;
        t = list_add(t, e);
        temp->next = t;
    }
    else
    {
        struct list *temp2 = temp;
        while (temp->next && temp->data > e)
        {
            temp2 = temp;
            temp = temp->next;
        }
        struct list *t = NULL;
        t = list_add(t, e);
        if (t)
        {
            if (!temp->next)
            {
                temp->next = t;
            }
            else
            {
                temp2->next = t;
                t->next = temp;
            }
        }
    }
    return l;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (l)
    {
        struct list *temp = l;
        while (temp->next)
        {
            if (predicate(temp->data) == 1)
            {
                int data = temp->data;
                temp = temp->next;
                l = list_remove(l, data);
            }
            else
            {
                temp = temp->next;
            }
        }
        if (predicate(l->data))
        {
            l = list_remove(l, l->data);
        }
    }
    return l;
}
