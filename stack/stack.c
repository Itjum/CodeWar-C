#include "stack.h"

#include <stddef.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = malloc(sizeof(struct stack));
    if (s == NULL)
    {
        if (new == NULL)
            return NULL;
        new->data = e;
        new->next = NULL;
        return new;
    }
    else
    {
        if (new == NULL)
            return s;
        new->data = e;
        new->next = s;
        return new;
    }
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        struct stack *top = s;
        s = s->next;
        free(top);
        return s;
    }
}

int stack_peek(struct stack *s)
{
    return s->data;
}
