#include "lca.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int test[9];
    test[0] = 0;
    test[1] = 1;
    test[2] = 4;
    test[3] = 5;
    test[4] = 9;
    test[5] = 10;
    test[6] = 18;
    test[7] = 22;
    test[8] = 42;
    int res = lca(test, 9, 9, 10);
    printf("%d\n", res);
}
