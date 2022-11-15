#include <stddef.h>
#include <stdlib.h>

void to_dirt(char **map, int i, int j)
{
    if (map[i][j] == '.')
    {
        map[i][j] = '#';
        to_dirt(map, i - 1, j);
        to_dirt(map, i, j - 1);
        to_dirt(map, i + 1, j);
        to_dirt(map, i, j + 1);
    }
}

int lakes(char **map, int width, int height)
{
    int res = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                res++;
                to_dirt(map, i, j);
            }
        }
    }
    return res;
}
