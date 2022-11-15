#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (needle == NULL || needle[0] == '\0')
    {
        return 0;
    }
    int t = 0;
    int i = 0;
    int j = 0;
    while (haystack[i] != '\0')
    {
        j = 0;
        t = 0;
        if (needle[0] == haystack[i])
        {
            int temp = i;
            while (haystack[temp] != '\0' && needle[j] != '\0' && t == 0)
            {
                if (haystack[temp] != needle[j])
                {
                    t = 1;
                }
                j++;
                temp++;
            }
            if (needle[j] == '\0' && t == 0)
            {
                return i;
            }
            i++;
        }
        i++;
    }
    return -1;
}
