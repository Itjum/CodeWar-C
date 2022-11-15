#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    for (size_t x = 0; x < matrices_size[0]; x++)
    {
        for (size_t j = 0; j < matrices_size[2]; j++)
        {
            out[x][j] = 0;
            for (size_t k = 0; k < matrices_size[1]; k++)
            {
                out[x][j] += mat1[x][k] * mat2[k][j];
            }
        }
    }
}
