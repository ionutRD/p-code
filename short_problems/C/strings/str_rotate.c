/**§
 * Rotate a given string with k >= 0
 * Ex: str = "abcd" and k = 1 => str = "bcda"
 */
#include <string.h>
#include <stdio.h>
#include <assert.h>

void str_reverse(char *str, int i, int j)
{
    if (str == NULL || i < 0 || j >= strlen(str))
        return;

    int left = i;
    int right = j;
    while (left < right) {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}

char* str_rotate(char *str, int k, int *err)
{
    if (k < 0 || str == NULL) {
        *err = -1;
        return NULL;
    }

    int sz = strlen(str);
    k %= sz;
    *err = 0;

    if (k == 0)
        return str;

    str_reverse(str, 0, sz - 1);
    str_reverse(str, 0, k - 1);
    str_reverse(str, k, sz - 1);
    return str;
}

int main(int argc, char **argv)
{
    int err = 0;
    printf("Test 1: str = abcd, k = 1 => %s\n", str_rotate(strdup("abcd"), 1, &err));
    assert(strcmp(str_rotate(strdup("abcd"), 1, &err), "dabc") == 0 && err == 0);
}
