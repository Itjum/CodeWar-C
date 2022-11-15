#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }
    int t = argv[2][0] - '0';
    while (t > 0)
    {
        t -= 1;
        puts(argv[1]);
    }
    return 0;
}
