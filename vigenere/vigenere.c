#include "vigenere.h"

#include <stddef.h>

char toUpper(char string)
{
    if (string >= 'a' && string <= 'z')
        string -= 32;
    return string;
}

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res += 1;
        s++;
    }
    return res;
}

void cipher(const char *key, const char *msg, char *res)
{
    int len = my_strlen(msg);
    int keylen = my_strlen(key);
    if (len == 1)
    {
        res[0] = ((toUpper(msg[0]) + toUpper(key[0])) % 26) + 'A';
        res[1] = '\0';
    }
    else
    {
        int j = 0; // index for key, goes back to 0 when reached keylen
        int i = 0; // index for msg
        for (i = 0; i < len; i++)
        {
            if (j == keylen)
                j = 0;
            if (msg[i] >= 'A' && msg[i] <= 'Z')
            {
                char c = key[j];
                if (c >= 'A' && c <= 'Z')
                    res[i] = (msg[i] - 'A' + c - 'A') % 26 + 'A';
                else
                    res[i] = (msg[i] - 'A' + c - 'a') % 26 + 'A';
                j++;
            }
            else if ((msg[i] >= 'a' && msg[i] <= 'z'))
            {
                char c = key[j];
                if (c >= 'A' && c <= 'Z')
                {
                    res[i] = (msg[i] - 'a' + c - 'A') % 26 + 'A';
                }
                else
                    res[i] = (msg[i] - 'a' + c - 'a') % 26 + 'A';
                j++;
            }
            else
            {
                res[i] = msg[i];
            }
        }
        res[i] = '\0';
    }
}

void decipher(const char *key, const char *msg, char *res)
{
    int len = my_strlen(msg);
    int keylen = my_strlen(key);
    if (len == 1)
    {
        res[0] = ((msg[0] - toUpper(key[0]) + 26) % 26) + 'A';
        res[1] = '\0';
    }
    else
    {
        int j = 0;
        int i = 0;
        for (i = 0; msg[i]; i++)
        {
            if (j == keylen)
                j = 0;
            if (msg[i] >= 'A' && msg[i] <= 'Z')
            {
                char c = key[j];
                char temp = 'a';
                if (c >= 'A' && c <= 'Z')
                    temp = 'A';
                char calc = (msg[i] - 'A' - (c - temp));
                if (calc < 0)
                    res[i] = calc % 26 + 'A' + 26;
                else
                    res[i] = calc % 26 + 'A';
                j++;
            }
            else if (msg[i] >= 'a' && msg[i] <= 'z')
            {
                char c = key[j];
                char temp = 'a';
                if (c >= 'A' && c <= 'Z')
                    temp = 'A';
                char calc = (msg[i] - 'a' - (c - temp));
                if (calc < 0)
                    res[i] = calc % 26 + 'A' + 26;
                else
                    res[i] = calc % 26 + 'A';
                j++;
            }
            else
            {
                res[i] = msg[i];
            }
        }
        res[i] = '\0';
    }
}
