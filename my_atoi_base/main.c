#include <stdio.h>

#include "my_atoi_base.c"

int main()
{
    char str[] = "77";
    int val = my_atoi_base(str, "01234567");
    printf("%d \n", val);
    return 0;
}
