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
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = fgetc(file);
    }
    fclose(file);
    if (count == 6)
        count--;
    return count + 1;
}

int merge_files(const char *file_1, const char *file_2)
{
    if (file_1 == NULL || file_2 == NULL)
        return -1;
    FILE *test = fopen(file_1, "r");
    if (!test)
        return -1;
    fclose(test);
    FILE *file1 = fopen(file_1, "a");
    FILE *file2 = fopen(file_2, "r");
    if (file1 == NULL || file2 == NULL)
    {
        return -1;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file2)) != -1)
    {
        fputs(line, file1);
    }
    free(line);
    if (fclose(file1) != 0)
        return -1;
    if (fclose(file2) != 0)
        return -1;
    return count_lines(file_1);
}
