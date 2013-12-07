/**
 * Replace the space with %20 in a given string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_space(char *str)
{
    if (str == NULL)
        return 0;

    int count = 0;
    int sz = strlen(str);
    for (int i = 0; i < sz; i++)
        if (str[i] == ' ')
            ++count;
    return count;
}

char *replace_str(char *str)
{
    if (str == NULL)
        return NULL;

    int sz = strlen(str);
    int count = count_space(str);
    int new_sz = sz + (count << 1);
    str = realloc(str, new_sz);
    str[new_sz] = '\0';
    int new_idx = new_sz - 1;
    int old_idx = sz - 1;

    for (int i = old_idx; i >=0; --i)
        if (str[i] == ' ') {
            str[new_idx] = '0';
            str[new_idx - 1] = '2';
            str[new_idx - 2] = '%';
            new_idx -= 3;
        } else {
            str[new_idx] = str[i];
            --new_idx;
        }

    return str;
}

int main(int argc, char **argv)
{
    printf("Test 1: str = 'ana are mere rosii' => %s\n",
            replace_str(strdup("ana are mere rosii")));
    return 0;
}
