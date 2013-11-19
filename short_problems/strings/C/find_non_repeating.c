/**
 * Find the first non-repeating character in a string
 * For example for "geeksforgeeks" the first non-repeating
 * character is 'f'
 * This must be done in O(n) time complexity with one
 * string traversal
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define NO_OF_CHARS 256

typedef struct {
    int index;
    int no_app;
} char_info_t;

char find_first_non_repeating(const char *str)
{
    if (str == NULL)
        return '\0';

    char_info_t table[NO_OF_CHARS];
    int sz = strlen(str);
    int first_idx = INT_MAX;
    int first_char = '\0';

    for (int i = 0; i < NO_OF_CHARS; i++) {
        table[i].index = -1;
        table[i].no_app = 0;
    }

    for (int i = 0; i < sz; ++i) {
        if (table[str[i]].no_app == 0)
            table[str[i]].index = i;
        ++table[str[i]].no_app;
    }

    for (int i = 0; i < NO_OF_CHARS; i++)
        if (table[i].no_app == 1 && table[i].index < first_idx) {
            first_idx = table[i].index;
            first_char = i;
        }

    return first_char;
}

int main(int argc, char **argv)
{
    printf("Test 1: geeksforgeeks => %c\n", find_first_non_repeating("geeksforgeeks"));
    printf("Test 2: ana are mere => %c\n", find_first_non_repeating("ana are mere"));
    printf("Test 3: this is a dummy test => %c\n", find_first_non_repeating("this is a dummy test"));
    return 0;
}
