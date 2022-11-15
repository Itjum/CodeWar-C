#include <stddef.h>
#include <stdio.h>

int count_words(const char *file_in)
{
    FILE *file = fopen(file_in, "r");
    if (file == NULL)
        return -1;
    int count = 0;
    int loops = 0;
    int lines = 0;
    int lfverif = 0;
    int prev = 1;
    char read;
    while ((read = fgetc(file)) != -1)
    {
        if (read == '\n')
            lines++;
        if (read == ' ' || read == '\t' || read == '\n')
        {
            if (prev == 0)
                count++;
            prev = 1;
        }
        else
        {
            lfverif = 1;
            prev = 0;
        }
        loops++;
    }
    if ((loops <= 1 && prev == 1) || lfverif == 0)
    {
        count = 0;
    }
    else if (lines != 1)
    {
        count++;
    }
    fclose(file);
    return count;
}
