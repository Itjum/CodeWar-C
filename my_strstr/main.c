#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// PROTOTYPE OR HEADER FILE
#include "my_strstr.h"

static void tests_verification()
{
    // WHEN
    const char *t1 = malloc(sizeof(char));
    const char *t2 = malloc(sizeof(char));
    t1 = "les papis qui pissent sous le chameau";
    t2 = "";
    int res = my_strstr(t1, t2);
    if (res == 15)
    {
        // GOOD
        printf("OK\n");
    }
    else
    {
        // NOT GOOD
        printf("res: %d \n", res);
        printf("KO\n");
    }
}

int main(void)
{
    // GIVEN
    tests_verification();

    return 0;
}
