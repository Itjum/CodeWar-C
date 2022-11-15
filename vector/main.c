#include <stdio.h>

#include "vector.h"

int main(void)
{
    struct vector *v1 = vector_init(8);
    struct vector *v2 = vector_init(16);
    printf("vector 1 capacity: %lu\n", v1->capacity);
    printf("vector 2 capacity: %lu\n", v2->capacity);
    v1 = vector_resize(v1, 16);
    v2 = vector_resize(v2, 8);
    printf("vector 1 capacity after realloc: %lu\n", v1->capacity);
    printf("vector 2 capacity after realloc: %lu\n", v2->capacity);
    v1 = vector_append(v1, 2);
    v1 = vector_append(v1, 4);
    v1 = vector_append(v1, 6);
    v1 = vector_insert(v1, 3, 7);
    v1 = vector_append(v1, 8);
    v1 = vector_append(v1, 8);
    printf("print v1:\n");
    vector_print(v1);
    printf("vector after 2 removes:\n");
    v1 = vector_remove(v1, 5);
    v1 = vector_remove(v1, 2);
    vector_print(v1);
    printf("print v1 after reset:\n");
    v1 = vector_reset(v1, 8);
    vector_print(v1);
    vector_destroy(v1);
    vector_destroy(v2);
}
