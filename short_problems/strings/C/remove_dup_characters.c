/**
 * Remove duplicate characters from a given string
 * Method 1: Time Complexity O(n)
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define NO_OF_CHARS 256


char *strremdup(char *str)
{
    char table[NO_OF_CHARS] = { 0 };
    int init_idx = 0;
    int result_idx = 0;
    int len = strlen(str);

    if (str == NULL)
        return NULL;

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
    printf("Test 1: geeksforgeeks = %s\n", strremdup(strdup("geeksforgeeks")));
    printf("Test 1: ana are mere = %s\n", strremdup(strdup("ana are mere")));

    return 0;
}
