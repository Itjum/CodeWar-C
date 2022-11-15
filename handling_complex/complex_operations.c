#include "complex_operations.h"

#include <stddef.h>

#include "complex.h"

struct complex neg_complex(struct complex a)
{
    struct complex new;
    new.real = -1 * a.real;
    new.img = -1 * a.img;
    return new;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex new;
    new.real = a.real + b.real;
    new.img = a.img + b.img;
    return new;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex new;
    new.real = a.real - b.real;
    new.img = a.img - b.img;
    return new;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex new;
    new.real = (a.real * b.real) - (a.img * b.img);
    new.img = (a.real * b.img) + (a.img * b.real);
    return new;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex new;
    new.real =
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
    new.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
    return new;
}
