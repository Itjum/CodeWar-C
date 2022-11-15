#include "connect4.h"

int check_vertical(char *game[], size_t columns, size_t lines)
{
    size_t i;
    size_t j;

    for (i = 0; i < lines - 3; i++) // changed
    {
        for (j = 0; j < columns; j++)
        {
            if (game[i][j] != '-')
            {
                if (game[i][j] == game[i + 1][j] && game[i][j] == game[i + 2][j]
                    && game[i][j] == game[i + 3][j])
                {
                    if (game[i][j] == 'X')
                        return 1;
                    if (game[i][j] == 'O')
                        return 2;
                }
            }
        }
    }
    return 0;
}

int check_horizontal(char *game[], size_t columns, size_t lines)
{
    size_t i;
    size_t j;

    for (i = 0; i < lines; i++) // changed
    {
        for (j = 0; j < columns - 3; j++)
        {
            if (game[i][j] != '-')
            {
                if (game[i][j] == game[i][j + 1] && game[i][j] == game[i][j + 2]
                    && game[i][j] == game[i][j + 3])
                {
                    if (game[i][j] == 'X')
                        return 1;
                    if (game[i][j] == 'O')
                        return 2;
                }
            }
        }
    }
    return 0;
}

int check_diagonals2(char *game[], size_t columns, size_t lines)
{
    size_t i;
    size_t j;

    for (i = 0; i < lines - 3; i++)
    {
        for (j = 3; j < columns; j++)
        {
            if (game[i][j] != '-')
            {
                if (game[i][j] == game[i + 1][j - 1]
                    && game[i][j] == game[i + 2][j - 2]
                    && game[i][j] == game[i + 3][j - 3])
                {
                    if (game[i][j] == 'X')
                        return 1;
                    if (game[i][j] == 'O')
                        return 2;
                }
            }
        }
    }
    return 0;
}

int check_diagonals(char *game[], size_t columns, size_t lines)
{
    size_t i;
    size_t j;

    for (i = 0; i < lines - 3; i++)
    {
        for (j = 0; j < columns - 3; j++)
        {
            if (game[i][j] != '-')
            {
                if (game[i][j] == game[i + 1][j + 1]
                    && game[i][j] == game[i + 2][j + 2]
                    && game[i][j] == game[i + 3][j + 3])
                {
                    if (game[i][j] == 'X')
                        return 1;
                    if (game[i][j] == 'O')
                        return 2;
                }
            }
        }
    }
    return 0;
}

int check_validity(int res, int res1, int res2, int res3, int res4)
{
    if (res4 != 0)
    {
        if ((res1 == 0) && (res2 == 0) && (res3 == 0))
            res = res4;
        else if ((res1 != 0) && (res4 != res1))
            return 0;
        else if ((res2 != 0) && (res4 != res2))
            return 0;
        else if ((res3 != 0) && (res4 != res3))
            return 0;
    }
    return res;
}

int connect4(char *game[], size_t columns, size_t lines)
{
    int res = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    int res4 = 0;
    res1 = check_vertical(game, columns, lines);
    if (res1 != 0)
    {
        res = res1;
    }
    res2 = check_horizontal(game, columns, lines);
    if (res2 != 0)
    {
        if (res1 == 0)
            res = res2;
        else if (res1 != res2)
            return 0;
    }
    res3 = check_diagonals(game, columns, lines);
    if (res3 != 0)
    {
        if ((res1 == 0) && (res2 == 0))
            res = res3;
        else if ((res1 != 0) && (res3 != res1))
            return 0;
        else if ((res2 != 0) && (res3 != res2))
            return 0;
    }
    res4 = check_diagonals(game, columns, lines);
    res = check_validity(res, res1, res2, res3, res4);
    return res;
}
