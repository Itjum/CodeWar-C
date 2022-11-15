#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int count_line(const char *filename)
{
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return -1;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file)) != -1)
    {
        count++;
    }
    free(line);
    fclose(file);
    return count;
}

int replace_line(const char *file_inn, const char *file_out,
                 const char *content, int n)
{
    int nblines = count_line(file_inn);
    if (nblines < 0)
        return -1;
    int count = 0;
    FILE *file1 = fopen(file_inn, "r");
    FILE *file2 = fopen(file_out, "w");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file1)) != -1)
    {
        if (count == n)
        {
            fputs(content, file2);
            count++;
        }
        else
        {
            count++;
            fputs(line, file2);
        }
    }
    free(line);
    fclose(file1);
    fclose(file2);
    return 1;
}
