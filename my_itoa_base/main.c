#include <assert.h>
#include <stdio.h>
#include "my_itoa_base.h"
#include <stdlib.h>
#include <string.h>

// PROTOTYPE OR HEADER FILE
// ...

static void tests_verification()
{
    // WHEN

    char *res = malloc(sizeof(char));
    //res = my_itoa_base(42, res, "0123456789ABCDEF");
  res = my_itoa_base(-32, res, "0123456789abcdef");
//    res = my_itoa_base(12, res, "01");
//    res = my_itoa_base(80, res, "0123456");
    // THEN
    if (strncmp(res,"2A", 2) == 0)
    {
        // GOOD
        printf("OK\n");
    }
    else
    {
        // NOT GOOD
        printf("KO\n");
        printf("%c ", res[0]);
        printf("%c ", res[1]);
        printf("%c ", res[2]);
        printf("%c ", res[3]);
    }
}

int main(void)
{
    // GIVEN
    tests_verification();

    return 0;
}
