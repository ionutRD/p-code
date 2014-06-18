/**
 * Remove every 'bc' from a given string
 */
#include <stdio.h>
#include <string.h>

char *remove_bc(char *str)
{
    if (str == NULL)
        return NULL;

    int sz = strlen(str);
    int old_idx = 0;
    int new_idx = 0;

    while (old_idx < sz) {
        if (old_idx < sz - 1 && str[old_idx] == 'b'
                && str[old_idx + 1] == 'c' ) {
            old_idx += 2;
        } else {
            str[new_idx] = str[old_idx];
            ++old_idx;
            ++new_idx;
        }
    }

    str[new_idx] = '\0';
    return str;
}

int main(int argc, char **argv)
{
    printf("Test 1: str = 'cababcebc' => %s\n",
            remove_bc(strdup("cababcebc")));
    return 0;
}
