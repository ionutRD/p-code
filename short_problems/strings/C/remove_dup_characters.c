/**
 * Remove duplicate characters from a given string
 * Method 1: Time Complexity O(n)
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define NO_OF_CHARS 256


char *strremdup(char *str, int *err)
{
    char table[NO_OF_CHARS] = { 0 };
    int init_idx = 0;
    int result_idx = 0;
    int len = strlen(str);
    *err = 0;

    if (str == NULL) {
        *err = -1;
        return NULL;
    }

    while (init_idx < len) {
        if (!table[str[init_idx]]) {
            table[str[init_idx]] = 1;
            str[result_idx] = str[init_idx];
            ++result_idx;
        }
        ++init_idx;
    }

    str[result_idx] = '\0';
    return str;
}

int main(int argc, char** argv)
{
    int  err = 0;
    printf("Test 1: geeksforgeeks = %s\n", strremdup(strdup("geeksforgeeks"), &err));
    assert(strcmp(strremdup(strdup("geeksforgeeks"), &err), "geksfor") == 0 && err == 0);
    printf("Test 2: ana are mere = %s\n", strremdup(strdup("ana are mere"), &err));
    assert(strcmp(strremdup(strdup("ana are mere"), &err), "an rem") == 0 && err == 0);

    return 0;
}
