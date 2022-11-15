#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int count_lines(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return -1;
    char c = fgetc(file);
    int count = 0;
    int verif = 0;
    while (c != EOF)
    {
        if (c == '\n')
        {
            count++;
            verif = 1;
        }
        else
            verif = 0;
        c = fgetc(file);
    }
    fclose(file);
    if (!verif)
        count++;
    return count;
}

int insert_line(const char *file_inn, const char *file_out, const char *content,
                int n)
{
    if (!file_out || !file_inn)
        return -1;
    FILE *file1 = fopen(file_inn, "r");
    FILE *file2 = fopen(file_out, "w");
    if (!file1 || !file2)
        return -1;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int count = 0;
    int verif = 0;
    while ((nread = getline(&line, &len, file1)) != -1)
    {
        if (count == n)
        {
            fputs(content, file2);
            fputs(line, file2);
            verif = 1;
            count++;
        }
        else
        {
            fputs(line, file2);
        }
        count++;
    }
    while (count++ < n)
        fputs("\n", file2);
    if (!verif)
        fputs(content, file2);
    free(line);
    fclose(file1);
    fclose(file2);
    count = count_lines(file_out);
    return count;
}
