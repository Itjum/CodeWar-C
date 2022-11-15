#include <stddef.h>
#include <stdio.h>

int reverse_content(const char *file_in, const char *file_out)
{
    FILE *file1 = fopen(file_in, "r");
    FILE *file2 = fopen(file_out, "w");
    if (file1 == NULL || file2 == NULL)
        return -1;
    char read;
    int verif = fseek(file1, -1, SEEK_END);
    while (verif == 0)
    {
        read = fgetc(file1);
        if (read == -1)
            break;
        fputc(read, file2);
        if (read == '\n')
            verif = fseek(file1, -2, SEEK_CUR);
        else
            verif = fseek(file1, -2, SEEK_CUR);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}

/*
// char temp[1000];
if (read == '\n')
{
temp[i] = '\n';
int j = 0;
while (j <= i)
{
    fputc(temp[i], file2);
    j++;
}
i = 0;
int tt = 1;
while (tt <= i)
{
    fseek(file1, -tt, SEEK_CUR);
    read = fgetc(file1);
    fputc(read, file2);
    tt++;
}
fseek(file1, i, SEEK_CUR);
}
else
{
i++;
}*/
